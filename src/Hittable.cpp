//
// Created by tuurm on 25/06/2023.
//

#include "Hittable.h"

void Hit::SetFaceNormal(const Ray &ray, const Vector3 &outwardNormal) {
    frontFace = ray.GetDirection().Dot(outwardNormal) < 0.0;
    normal = frontFace > 0 ? outwardNormal : -outwardNormal;
}
