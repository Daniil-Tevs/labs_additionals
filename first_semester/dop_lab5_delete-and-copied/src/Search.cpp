#include <iostream>
char Search(std::string& word)
{
    char b_max=' ';
    for(char i : word)
    {
        if(std::count(word.begin(), word.end(), i)>std::count(word.begin(), word.end(), b_max))
            b_max=i;
    }
    return b_max;
}