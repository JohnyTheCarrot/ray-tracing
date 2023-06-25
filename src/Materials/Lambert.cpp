//
// Created by tuurm on 25/06/2023.
//

#include "Lambert.h"
#include "../Hittable.h"

bool Lambert::Scatter(const Ray &ray, const Hit &hit, Vector3 &attenuation, Ray &scattered) const {
    Vector3 scatterDirection{ hit.normal + Vector3::RandomUnit() };
    scattered = Ray{ hit.point, scatterDirection };
    attenuation = m_Albedo;

    if (scatterDirection.IsNearZero())
        scatterDirection = hit.normal;

    return true;
}
