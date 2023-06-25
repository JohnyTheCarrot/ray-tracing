//
// Created by tuurm on 25/06/2023.
//

#ifndef RAY_TRACING_CAMERA_H
#define RAY_TRACING_CAMERA_H


#include "Vector3.h"
#include "Ray.h"

class Camera {
public:
    Camera();

    [[nodiscard]]
    Ray GetRay(double u, double v) const;

private:
    Vector3 m_Origin;
    Vector3 m_LowerLeftCorner;
    Vector3 m_Horizontal;
    Vector3 m_Vertical;
};


#endif //RAY_TRACING_CAMERA_H
