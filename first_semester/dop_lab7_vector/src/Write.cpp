#include <fstream>
#include <vector>

void Write(std::vector<int> vec)
{
    std::ofstream out("output.txt");
    for(const auto& v : vec)
        out<<v<<" ";
    out.close();
}

