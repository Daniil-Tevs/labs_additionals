#pragma once
#include <iostream>
class Maded_vector
{
private:
    int n=0;
    float* mass = new float[n];
    float* mass_vs = new float[n+1];
public:
    Maded_vector()
    {
        n=0;
    }
    ~Maded_vector()
    {

    }
    void pushback(float a)
    {
        float* mass_vs = new float[n+1];
        for(int i=0;i<n;i++)
            mass_vs[i]=mass[i];
        mass_vs[n]=a;
        n+=1;
    }
    int getSize()
    {
        return n;
    }
    void Write();
};