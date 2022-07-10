#include <fstream>
#include "functions.h"

void Read(std::string &word)
{
    std::ifstream in("input.txt");
    int i=0;
    in>>word;
    in.close();
}