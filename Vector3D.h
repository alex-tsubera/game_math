#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>

struct Vector3D
{
    float x;
    float y;
    float z;

    Vector3D() = default;
    Vector3D(float x, float y, float z) : x(x), y(y), z(z) {}

    float magnitude() const { return std::hypot(x, y, z); }
    Vector3D normalized() const { return (*this) / magnitude(); }

    float &operator [](int i) { return (&x)[i]; }
    const float &operator [](int i) const { return (&x)[i]; }

    Vector3D &operator *=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vector3D &operator /=(float s)
    {
        s = 1.0f / s;
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vector3D &operator +=(const Vector3D &v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vector3D &operator -=(const Vector3D &v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    static float dotProduct(const Vector3D &a, const Vector3D &b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    static Vector3D crossProduct(const Vector3D &a, const Vector3D &b)
    {
        return Vector3D(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
    }
};

inline Vector3D operator *(const Vector3D &v, float s)
{
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

inline Vector3D operator /(const Vector3D &v, float s)
{
    s = 1.0f / s;
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

inline Vector3D operator -(const Vector3D &v)
{
    return Vector3D(-v.x, -v.y, -v.z);
}

inline Vector3D operator +(const Vector3D &a, const Vector3D &b)
{
    return Vector3D(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline Vector3D operator -(const Vector3D &a, const Vector3D &b)
{
    return Vector3D(a.x - b.x, a.y - b.y, a.z - b.z);
}

#endif /* VECTOR3D_H */
