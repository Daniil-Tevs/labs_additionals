#include <fstream>
#include <vector>

void Read(std::vector<int> &vec)
{
    std::ifstream in("input.txt");
    int a;
    while(!in.eof())
    {
        in>>a;
        vec.push_back(a);
    }
    in.close();
}