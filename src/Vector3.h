//
// Created by tuurm on 25/06/2023.
//

#ifndef RAY_TRACING_VECTOR3_H
#define RAY_TRACING_VECTOR3_H


class Vector3 {
public:
    Vector3() : m_Elements{0.0, 0.0, 0.0} {}

    Vector3(
            double x,
            double y,
            double z
    ) : m_Elements{
            x,
            y,
            z
    } {}

    [[nodiscard]]
    double GetX() const;

    [[nodiscard]]
    double GetY() const;

    [[nodiscard]]
    double GetZ() const;

    Vector3 operator-() const;

    Vector3 &operator+=(const Vector3 &other);

    Vector3 &operator*=(const Vector3 &other);

    Vector3 &operator*=(double scalar);

    Vector3 &operator/=(double scalar);

    Vector3 operator+(double scalar) const;

    Vector3 operator*(double scalar) const;

    Vector3 operator/(double scalar) const;

    friend Vector3 operator+(double scalar, const Vector3 &other);

    friend Vector3 operator*(double scalar, const Vector3 &other);

    friend Vector3 operator/(double scalar, const Vector3 &other);

    Vector3 operator+(const Vector3 &other) const;

    Vector3 operator*(const Vector3 &other) const;

    Vector3 operator/(const Vector3 &other) const;

    [[nodiscard]]
    double Dot(const Vector3 &other) const;

    [[nodiscard]]
    Vector3 Cross(const Vector3 &other) const;

    [[nodiscard]]
    Vector3 Normalized() const;

    [[nodiscard]]
    double GetLength() const;

    [[nodiscard]]
    double GetLengthSquared() const;

private:
    double m_Elements[3];
};


#endif //RAY_TRACING_VECTOR3_H
