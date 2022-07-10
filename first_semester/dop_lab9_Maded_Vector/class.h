#pragma once
#include <iostream>
class Maded_vector
{
private:
public:
    int n=0;
    float* mass = new float[n];
    Maded_vector()
    {

    }
    ~Maded_vector()
    {

    }
    void Write();
    void Read();
};