//
// Created by tuurm on 25/06/2023.
//

#include <cmath>
#include "Sphere.h"

//bool Sphere::IsHitting(const Ray &ray, double tMin, double tMax, Hit &hitOut) const {
//    Vector3 oc{ ray.GetOrigin() - m_Center };
//    double a{ ray.GetDirection().Dot(oc) };
//    double delta = a * a - (oc.GetLengthSquared() - m_Radius * m_Radius);
//
//    if (delta < 0)
//        return false;
//
//    double sqrtDelta{ sqrt(delta) };
//    double rootOne{ -a + sqrtDelta };
//    double rootTwo{ -a - sqrtDelta };
//    double root{ rootOne };
//
//    if (root < tMin || root > tMax) {
//        root = rootTwo;
//
//        if (root < tMin || root > tMax)
//            return false;
//    }
//
//    hitOut.distanceFromOrigin = root;
//    hitOut.point = ray.At(hitOut.distanceFromOrigin);
//
//    Vector3 outwardNormal{ (hitOut.point - m_Center) / m_Radius };
//    hitOut.SetFaceNormal(ray, outwardNormal);
//
//    return true;
//}

bool Sphere::IsHitting(const Ray &ray, double tMin, double tMax, Hit &hitOut) const {
    Vector3 oc{ ray.GetOrigin() - m_Center };
    double a{ ray.GetDirection().GetLengthSquared() };
    double halfB{ oc.Dot(ray.GetDirection()) };
    double c{ oc.GetLengthSquared() - m_Radius * m_Radius };

    double discriminant{ halfB * halfB - a * c };
    if (discriminant < 0)
        return false;
    double sqrtDiscriminant = sqrt(discriminant);

    double root = (-halfB - sqrtDiscriminant) / a;
    if (root < tMin || tMax < root) {
        root = (-halfB + sqrtDiscriminant) / a;
        if (root < tMin || tMax < root)
            return false;
    }

    hitOut.distanceFromOrigin = root;
    hitOut.point = ray.At(root);
    Vector3 outwardNormal{ (hitOut.point - m_Center) / m_Radius };
    hitOut.SetFaceNormal(ray, outwardNormal);

    return true;
}