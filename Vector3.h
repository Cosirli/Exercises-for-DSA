#ifndef _VECTOR3_H
#define _VECTOR3_H

#include <iostream>

struct Vector3
{
    float x = 0.0f, y = 0.0f, z = 0.0f;

    Vector3() = default;
    Vector3(float scalar)
        : x(scalar), y(scalar), z(scalar) {}
    Vector3(float x, float y, float z)
        : x(x), y(y), z(z) {}

    Vector3(const Vector3& other)
        : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copied!" << std::endl;
    }

    Vector3(Vector3&& other) noexcept
        : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Moved!" << std::endl;
    }

    Vector3& operator=(const Vector3& other)
    {
        std::cout << "Copy" << std::endl;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vector3& operator=(Vector3&& other) noexcept
    {
        std::cout << "Move" << std::endl;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    ~Vector3() 
    {
        std::cout << "Destroyed!" << std::endl;
    }
};

#endif // _VECTOR3_H
