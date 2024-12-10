#include <iostream>
#include <cstring>

template<typename T, size_t S>
class Array
{
public:
    constexpr size_t Size() const { return S; }

    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; }

    T* Data() { return m_Data; }
    const T* Data() const { return m_Data; }
    
    /*Array(size_t size)
    {
        m_Data = (int*)alloca(size * sizeof(int));  // dynamically allocate memory on the stack
    } */

private:
    T m_Data[S];
};

int main()
{
    size_t size = 5;
    Array<int, 7> data;
    memset(data.Data(), 0, data.Size() * sizeof(int));

    data[0] = 2;
    data[1] = 3;

    for (size_t i = 0; i < data.Size(); ++i)
        std::cout << data[i] << std::endl;


    static_assert(data.Size() < 10, "Size is too large!");

    Array<std::string, data.Size()> strings;

    std::cin.get();
}
