//
// Created by tuurm on 25/06/2023.
//

#ifndef RAY_TRACING_MATERIAL_H
#define RAY_TRACING_MATERIAL_H

struct Hit;

class Ray;

class Vector3;

class Material {
public:
    virtual bool Scatter(const Ray &ray, const Hit &hit, Vector3& attenuation, Ray &scattered) const = 0;
};


#endif //RAY_TRACING_MATERIAL_H
