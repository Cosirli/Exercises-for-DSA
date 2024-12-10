#include <iostream>
#include <cstring>

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* str)
    {
        m_Size = strlen(str);
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, str, m_Size);  // not sure whether str is null-terminated
        m_Buffer[m_Size] = 0;
    }

    // The default copy constructor: a shallow copy of data members 
    /*
    String(const String& src)
        : m_Buffer(src.m_Buffer), m_Size(src.m_Size) {} 
    */
    // Copy constructor is a constructor as well
    String(const String& src)
        : m_Size(src.m_Size)
    {
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, src.m_Buffer, m_Size + 1);
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);

};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

void PrintString(const String& string)
{
    std::cout << string << std::endl;
}

int main()
{
    String string = "Hello";
    String second = string;    // implicitly calls the copy constructor
    String third(string);      // explicitly calls copy constructor
    second[1] = 'a';
    PrintString(string);
    PrintString(second);

    std::cin.get();
    return 0;
}
