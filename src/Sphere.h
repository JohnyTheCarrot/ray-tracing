//
// Created by tuurm on 25/06/2023.
//

#ifndef RAY_TRACING_SPHERE_H
#define RAY_TRACING_SPHERE_H


#include "Vector3.h"
#include "Hittable.h"

class Sphere : public Hittable {
public:
    Sphere(const Vector3 &center, double radius)
        : m_Center{ center }
        , m_Radius{ radius }
    {};

    bool IsHitting(const Ray &ray, double tMin, double tMax, Hit &hitOut) const override;

private:
    Vector3 m_Center;
    double m_Radius;
};


#endif //RAY_TRACING_SPHERE_H
