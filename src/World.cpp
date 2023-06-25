//
// Created by tuurm on 25/06/2023.
//

#include "World.h"

void World::Clear() {

}

void World::Add(std::unique_ptr<Hittable>&& object) {
    m_Objects.push_back(std::move(object));
}

bool World::IsHitting(const Ray &ray, double tMin, double tMax, Hit &hitOut) const {
    Hit hit;
    bool hasHitSomething{ false };
    double closestDistance{ tMax };

    for (const std::unique_ptr<Hittable>& object : m_Objects) {
        if (object->IsHitting(ray, tMin, closestDistance, hit)) {
            hasHitSomething = true;
            closestDistance = hit.distanceFromOrigin;
            hitOut = hit;
        }
    }

    return hasHitSomething;
}
