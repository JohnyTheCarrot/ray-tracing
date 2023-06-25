//
// Created by tuurm on 25/06/2023.
//

#ifndef RAY_TRACING_RAY_H
#define RAY_TRACING_RAY_H

#include "Vector3.h"

class World;

constexpr int MAX_DEPTH{ 50 };

class Ray {
public:
    Ray(const Vector3 &origin, const Vector3 &direction);

    [[nodiscard]]
    const Vector3 &GetOrigin() const;

    [[nodiscard]]
    const Vector3 &GetDirection() const;

    [[nodiscard]]
    Vector3 At(double t) const;

    [[nodiscard]]
    Vector3 GetColor(const World &world, int depth = 0) const;

private:
    Vector3 m_Origin;
    Vector3 m_Direction;
};


#endif //RAY_TRACING_RAY_H
