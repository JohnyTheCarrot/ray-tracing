//
// Created by tuurm on 25/06/2023.
//

#ifndef RAY_TRACING_HITTABLE_H
#define RAY_TRACING_HITTABLE_H


#include "Ray.h"

struct Hit {
    Vector3 point;
    Vector3 normal;
    double distanceFromOrigin;
    bool frontFace;

    void SetFaceNormal(const Ray &ray, const Vector3 &outwardNormal);
};

class Hittable {
public:
    virtual ~Hittable() = default;

    virtual bool IsHitting(const Ray &ray, double tMin, double tMax, Hit &hitOut) const = 0;
};


#endif //RAY_TRACING_HITTABLE_H
