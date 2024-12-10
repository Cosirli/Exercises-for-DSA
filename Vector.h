#ifndef _VECTOR_H
#define _VECTOR_H

#include <cstring>
#include <memory>
template <typename T>
class Vector
{
public:
    Vector()
        : m_Size(0), m_Capacity(2)
    {
        ReAlloc(2);
    }

    Vector(size_t size)
        : m_Size(size), m_Capacity(size)
    {
        m_Data = new T[size];
    }

    Vector(const Vector& other)
    {
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;
        m_Data = new T[m_Capacity];
        memcpy(m_Data, other.m_Data, m_Size * sizeof(T));
    }

    Vector(Vector&& other) noexcept
    {
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Capacity = 0;
        other.m_Data = nullptr;
    }

    ~Vector()
    {
        delete[] m_Data;
    }
    
    
    void PushBack(const T& value)
    {
        if (m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);
        m_Data[m_Size++] = value;
    }

    size_t Size() const { return m_Size; }

    T& operator[](size_t index) 
    {
        if (index >= m_Size)
        {
            return T{};
        }

        return m_Data[index];
    }
    const T& operator[](size_t index) const
    {
        return m_Data[index];
    }

private:
    void ReAlloc(size_t newCapacity) 
    {
        // 1. Allocate a new block of memory
        // 2. Copy or move existing elements into the new block
        // 3. Delete the old block

        T* newBlock = new T[newCapacity];

        if (newCapacity < m_Size)
            m_Size = newCapacity;

        for (size_t i = 0; i < m_Size; ++i)
            newBlock[i] = std::move(m_Data[i]);

        delete[] m_Data;
        m_Data = newBlock;
        m_Capacity = newCapacity;
    }
private:
    T* m_Data = nullptr;

    size_t m_Size = 0;
    size_t m_Capacity = 0;
};

#endif // _VECTOR_H
