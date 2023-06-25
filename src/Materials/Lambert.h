//
// Created by tuurm on 25/06/2023.
//

#ifndef RAY_TRACING_LAMBERT_H
#define RAY_TRACING_LAMBERT_H


#include "Material.h"
#include "../Vector3.h"

class Lambert final : public Material {
public:
    explicit Lambert(const Vector3& color) : m_Albedo{ color } {};

    bool Scatter(const Ray &ray, const Hit &hit, Vector3& attenuation, Ray &scattered) const override;

private:
    Vector3 m_Albedo;
};


#endif //RAY_TRACING_LAMBERT_H
