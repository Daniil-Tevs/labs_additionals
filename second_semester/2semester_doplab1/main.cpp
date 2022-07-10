#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
bool Palindrome(int i,std::string& word)
{
    if(i<word.length()-1-i)
    {
        if(tolower(word[i])==tolower(word[word.length()-i-1])) {
            if (Palindrome(i + 1, word))
                return true;
            else
                return false;
        }
    }
    else if(i >= word.length()-1-i && tolower(word[i])==tolower(word[word.length()-i-1]))
        return true;
    return false;
}
int main() {
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    std::ifstream in("../input.txt");
    std::string word;
    in>>word;
    if(Palindrome(0,word))
        std::cout<<word<<" is polindrome";
    else
        std::cout<<word<<" is not polindrome";
    return 0;
}
