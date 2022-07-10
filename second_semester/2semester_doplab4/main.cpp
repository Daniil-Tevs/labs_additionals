#include <iostream>
#include <fstream>
#include <vector>
#include "inc/bmp.h"
int main() {
    std::ifstream in("../word.txt");
    std::string tmp;
    std::vector<std::string> word;
    std::vector<char> v;
    while(!in.eof())
    {
        in>>tmp;
        word.push_back(tmp);
    }
    bmp image("../examples/example1.bmp");
    image.shorthand(30,1000,1000,word);
    image.write("../output.bmp");
    return 0;
}
