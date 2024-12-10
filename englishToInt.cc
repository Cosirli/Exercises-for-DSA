#include <string>
#include <iostream>

int lowercaseToInt(const std::string& str)
{
    int intRep = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        intRep *= 27;
        intRep += str.at(i) - 'a' + 1;
    }
    return intRep;
}

int returnTest()
{
    int a = 0;
    return (a++, a++, a++);
}

int callTest(int a)
{
    return a;
}

int main()
{
    int t = 0;
    std::cout << returnTest() << std::endl;   // output: 2
    std::cout << callTest(t++) << std::endl;  // output: 0
    int x = 0, y = 0;

    if (x++ || x)
        std::cout << "x: " << x << std::endl; // output: x: 1

    if (!y++ && y) 
        std::cout << "y: " << y << std::endl; // output: y: 1
    
    int z = (y--, x + y);
    std::cout << "z: " << z << std::endl;     // output: z: 0

    std::cin.get();
}
