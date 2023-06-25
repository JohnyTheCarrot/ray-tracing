//
// Created by tuurm on 25/06/2023.
//

#include <cmath>
#include "Vector3.h"

Vector3 Vector3::operator-() const {
    return {-m_Elements[0], -m_Elements[1], -m_Elements[2]};
}

Vector3 &Vector3::operator+=(const Vector3 &other) {
    m_Elements[0] += other.m_Elements[0];
    m_Elements[1] += other.m_Elements[1];
    m_Elements[2] += other.m_Elements[2];

    return *this;
}

Vector3 &Vector3::operator*=(const Vector3 &other) {
    m_Elements[0] *= other.m_Elements[0];
    m_Elements[1] *= other.m_Elements[1];
    m_Elements[2] *= other.m_Elements[2];

    return *this;
}

Vector3 &Vector3::operator*=(double scalar) {
    m_Elements[0] *= scalar;
    m_Elements[1] *= scalar;
    m_Elements[2] *= scalar;

    return *this;
}

Vector3 &Vector3::operator/=(double scalar) {
    *this *= 1.0 / scalar;

    return *this;
}

Vector3 Vector3::operator+(double scalar) const {
    return {
        m_Elements[0] + scalar,
        m_Elements[1] + scalar,
        m_Elements[2] + scalar
    };
}

Vector3 Vector3::operator*(double scalar) const {
    return {
        m_Elements[0] * scalar,
        m_Elements[1] * scalar,
        m_Elements[2] * scalar
    };
}

Vector3 Vector3::operator/(double scalar) const {
    return {
        m_Elements[0] / scalar,
        m_Elements[1] / scalar,
        m_Elements[2] / scalar
    };
}

Vector3 Vector3::operator+(const Vector3 &other) const {
    Vector3 vec{};
    vec += other;
    return vec;
}

Vector3 Vector3::operator*(const Vector3 &other) const {
    Vector3 vec{};
    vec *= other;
    return vec;
}

Vector3 Vector3::operator/(const Vector3 &other) const {
    Vector3 vec{};
    vec *= 1.0 / other;
    return vec;
}

double Vector3::GetX() const {
    return m_Elements[0];
}

double Vector3::GetY() const {
    return m_Elements[1];
}

double Vector3::GetZ() const {
    return m_Elements[2];
}

double Vector3::Dot(const Vector3 &other) const {
    return    m_Elements[0] * other.m_Elements[0]
            + m_Elements[1] * other.m_Elements[1]
            + m_Elements[2] * other.m_Elements[2];
}

Vector3 Vector3::Cross(const Vector3 &other) const {
    return {
        m_Elements[1] * other.m_Elements[2] - m_Elements[2] * other.m_Elements[1],
        m_Elements[0] * other.m_Elements[2] - m_Elements[2] * other.m_Elements[0],
        m_Elements[0] * other.m_Elements[1] - m_Elements[1] * other.m_Elements[0]
    };
}

Vector3 Vector3::Normalized() const {
    return *this / this->GetLength();
}

double Vector3::GetLength() const {
    return sqrt(GetLengthSquared());
}

double Vector3::GetLengthSquared() const {
    return this->Dot(*this);
}

Vector3 operator+(const double scalar, const Vector3 &other) {
    return other + scalar;
}

Vector3 operator*(const double scalar, const Vector3 &other) {
    return other * scalar;
}

Vector3 operator/(double scalar, const Vector3 &other) {
    return other * 1.0 / scalar;
}
