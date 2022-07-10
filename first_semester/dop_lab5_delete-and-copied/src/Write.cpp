#include <fstream>
#include <string>
#include "functions.h"

void Write(int mass[n],int dlina)
{
    std::ofstream out("output.txt");
    for(int i=0;i<=dlina;i++)
        out<<mass[i]<<" ";
    out.close();
}

