//
// Created by tuurm on 25/06/2023.
//

#include <limits>
#include "Ray.h"
#include "Sphere.h"
#include "World.h"

const double infinity = std::numeric_limits<double>::infinity();

Ray::Ray(const Vector3 &origin, const Vector3 &direction)
        : m_Origin{ origin }
        , m_Direction{ direction.Normalized() }
{

}

const Vector3 &Ray::GetOrigin() const {
    return m_Origin;
}

const Vector3 &Ray::GetDirection() const {
    return m_Direction;
}

Vector3 Ray::At(double t) const {
    return m_Origin + t * m_Direction;
}

Vector3 Ray::GetColor(const World &world, int depth) const {
    if (depth > MAX_DEPTH)
        return { 0, 0, 0 };

    Hit hitInfo{};
    if (world.IsHitting(*this, 0.0, infinity, hitInfo))
    {
        Vector3 target{ hitInfo.point + hitInfo.normal + Vector3::RandomInUnitSphere() };
        Ray subRay{ hitInfo.point, target - hitInfo.point };
        return 0.5 * subRay.GetColor(world, depth + 1);
    }

    double t{ 0.5 * (m_Direction.Normalized().GetY() + 1.0) };
    return (1.0 - t) * Vector3{ 1.0, 1.0, 1.0 } + t * Vector3 { 0.5, 0.7, 1.0 };
}
