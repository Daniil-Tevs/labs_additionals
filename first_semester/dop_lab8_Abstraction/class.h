#pragma once
#include <iostream>
class EqualTriangle
{
private:
    double m_dlina;
    void Error_Write();
public:
    EqualTriangle(int dlina)
    {
        if(dlina<0)
        {
            Error_Write();
            m_dlina=1;
        }
        else
            m_dlina=dlina;
    }
    ~EqualTriangle(){}
    int Perimetr();
    double Square();
    void Write();
};