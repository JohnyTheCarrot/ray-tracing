//
// Created by tuurm on 25/06/2023.
//

#ifndef RAY_TRACING_WORLD_H
#define RAY_TRACING_WORLD_H


#include <memory>
#include <vector>
#include "Hittable.h"

class World : public Hittable {
public:
    World() = default;

    void Clear();

    void Add(std::unique_ptr<Hittable>&& object);

    bool IsHitting(const Ray &ray, double tMin, double tMax, Hit &hitOut) const override;

private:
    std::vector<std::unique_ptr<Hittable>> m_Objects;
};


#endif //RAY_TRACING_WORLD_H
