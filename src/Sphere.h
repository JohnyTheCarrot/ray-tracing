//
// Created by tuurm on 25/06/2023.
//

#ifndef RAY_TRACING_SPHERE_H
#define RAY_TRACING_SPHERE_H


#include <utility>

#include "Vector3.h"
#include "Hittable.h"

class Sphere : public Hittable {
public:
    Sphere(const Vector3 &center, double radius, std::shared_ptr<Material> material)
        : m_Center{ center }
        , m_Radius{ radius }
        , m_MaterialPtr{std::move(material) }
    {};

    bool IsHitting(const Ray &ray, double tMin, double tMax, Hit &hitOut) const override;

private:
    Vector3 m_Center;
    double m_Radius;
    std::shared_ptr<Material> m_MaterialPtr;
};


#endif //RAY_TRACING_SPHERE_H
