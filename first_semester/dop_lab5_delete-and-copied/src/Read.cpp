#include <fstream>
#include "functions.h"

int Read(int mass[n])
{
    std::ifstream in("input.txt");
    int i=0;
    while(!in.eof()) {
        in>>mass[i];
        i++;
    }
    in.close();
    return i-1;
}