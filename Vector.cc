#include "Vector.h"
#include "Vector3.h"
#include <iostream>

template<typename T>
void PrintVector(const Vector<T>& vector)
{
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i] << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

template<>
void PrintVector(const Vector<Vector3>& vector)
{
    for (size_t i = 0; i < vector.Size(); ++i)
        std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

int main()
{
    Vector<std::string> vector;
    vector.PushBack("Yan");
    vector.PushBack("C++");

    PrintVector(vector);

    Vector<Vector3> vector3s;
    vector3s.PushBack(Vector3(1.0f));
    vector3s.PushBack(Vector3());
    vector3s.PushBack(Vector3(2.0f, 3.0f, 4.0f));

    std::cin.get();
    return 0;
}
