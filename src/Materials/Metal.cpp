//
// Created by tuurm on 25/06/2023.
//

#include "Metal.h"
#include "../Vector3.h"
#include "../Ray.h"
#include "../Hittable.h"

bool Metal::Scatter(const Ray &ray, const Hit &hit, Vector3 &attenuation, Ray &scattered) const {
    Vector3 reflected{ ray.GetDirection().Reflect(hit.normal) };
    scattered = Ray{ hit.point, reflected };
    attenuation = m_Albedo;
    return scattered.GetDirection().Dot(hit.normal) > 0;
}
