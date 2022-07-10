#include "functions.h"

namespace dt
{
    void Digit(int &a)
    {
        int d=a,sum=0;
        while(d>0)
        {
            sum+=d%10;
            d/=10;
        }
        if(sum%6==0)
            a=0;
    }
    bool First_Digit(int a)
    {
        int d;
        while(a>0)
        {
            d=a%10;
            a/=10;
        }
        if(d==1)
            return true;
        else
            return false;
    }
}

void Delete(int mass[n],int &dlina)
{
    for(int i=0;i<=dlina;i++)
    {
        dt::Digit(mass[i]);
        if(mass[i]==0)
        {
            for(int j=i;j<dlina;j++)
                mass[j]=mass[j+1];
            i-=1;
            dlina-=1;
        }
    }
}
void Duplication(int mass[n],int &dlina)
{
    for(int i=0;i<=dlina;i++)
    {
        if(dt::First_Digit(mass[i]))
        {
            for(int j=dlina+2;j>i;j--)
                mass[j]=mass[j-1];
            mass[i+1]=mass[i];
            i+=1;
            dlina+=1;
        }
    }
}