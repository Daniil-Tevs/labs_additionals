#include <fstream>
double Read()
{
    std::ifstream in("input.txt");
    double a;
    in>>a;
    return a;
}
