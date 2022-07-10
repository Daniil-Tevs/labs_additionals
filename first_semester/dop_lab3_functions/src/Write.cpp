#include <fstream>
#include <string>
#include "functions.h"

void Write(std::string word)
{
    std::ofstream out("output.txt");
    if(word.length()<=100)
    {
        char v=Search(word);
        out<<word<<"\n";
        out<<v;
    }
    else
        out<<"Error: Very long word";
    out.close();
}

