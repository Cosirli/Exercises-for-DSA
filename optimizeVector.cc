#include <vector>
#include <iostream>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z)
        : x(x), y(y), z(z) 
    {
    }
    
    Vertex(const Vertex& vertex)
        : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        std::cout << "Copied!" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

int main()
{
    std::cout << "Basic Operations:" << std::endl;

    std::vector<Vertex> vertices;
    vertices.push_back(Vertex{1, 2, 3});    // copy: 1
    vertices.push_back(Vertex(4, 5, 6));    // copy: 2 = 1 (resizing) + 1
    vertices.push_back({7, 8, 9});          // copy: 3 = 2 (resizing) + 1

    vertices.emplace_back(Vertex(0, 0, 0)); // copy: 1
    vertices.emplace_back(Vertex(0, 0, 0)); // copy: 5 = 4 (resizing) + 1
    vertices.emplace_back(Vertex(0, 0, 0)); // copy: 1
    vertices.emplace_back(0, 0, 0);         // copy: 0 (Constructed in place!)

    for (Vertex& v : vertices)
    {
        std::cout << v << std::endl;
    }

    vertices.erase(vertices.begin() + 1);   // Remove the second vertex
    std::cout << "After removing the 2nd vertex:" << std::endl;
    for (int i = 0; i < vertices.size(); ++i)
    {
        std::cout << vertices[i] << std::endl;
    }

    vertices.clear();

    std::cout << "Optimized Operations:" << std::endl;
    std::vector<Vertex> optimizedV;
    // Optimization 1: reserve memory for 3 optimizedV
    optimizedV.reserve(3);
    
    // Optimization 2: Pass the parameter list for the constructor to emplace_back() 
    //                 to construct the object in place
    optimizedV.emplace_back(1, 2, 3);
    optimizedV.emplace_back(4, 5, 6);
    optimizedV.emplace_back(7, 8, 9);
    
    std::cin.get();
}
