//
// Created by tuurm on 25/06/2023.
//

#include "Camera.h"

Camera::Camera() {
    double aspectRatio = 16.0 / 9.0;
    double viewportHeight = 2.0;
    double viewportWidth = aspectRatio * viewportHeight;
    double focalLength = 1;

    m_Origin = { 0, 0, 1 };
    m_Horizontal = { viewportWidth, 0, 0 };
    m_Vertical = { 0, viewportHeight, 0 };

    m_LowerLeftCorner = m_Origin - m_Horizontal / 2 - m_Vertical / 2 - Vector3{ 0, 0, focalLength };
}

Ray Camera::GetRay(double u, double v) const {
    return { m_Origin, m_LowerLeftCorner + u * m_Horizontal + v * m_Vertical - m_Origin };
}
