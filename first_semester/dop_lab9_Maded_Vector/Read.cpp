#include <fstream>
#include "class.h"
#include <string.h>

void Maded_vector::Read()
{
    std::ifstream in("input.txt");
    int a;
    std::string digits=" ";
    while(!in.eof())
    {
        in>>a;
        std::cout<<(char)a<<std::endl;
        n++;
    }
//    for(int i=0;i<n;i++)

}
