#include <fstream>
#include <iostream>
#include "class.h"

void EqualTriangle::Write()
{
    std::ofstream out("output.txt");
    out<<Perimetr()<<std::endl;
    out<<Square();
    out.close();
}
void EqualTriangle::Error_Write()
{
    std::cout<<"Error, dlina can't be less then 0\n";
    std::cout<<"Dlina will be standart = 1\n";
}