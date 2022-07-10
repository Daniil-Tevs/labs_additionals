#include <iostream>

//Посчитайте количество всех возможных счастливых трамвайных билетиков.
//Номер билета содержит 6 цифр.

int main()
{
    int mass[6]={0};
    int sum1=0,sum2=0;
    int s=0;
    while(mass[0]!=10)
    {
        sum1=0;
        sum2=0;
        for (int i = 0; i < 3; i++)
        {
            sum1 += mass[i];
            sum2 += mass[5 - i];
        }
        if (sum1 == sum2)
            s++;
        if(mass[2]==10)
        {
            mass[3]+=1;
            for(int i=0;i<3;i++)
                mass[5-i]=0;
        }
        if(mass[1]==10)
        {
            mass[3]+=1;
            for(int i=0;i<4;i++)
                mass[5-i]=0;
        }
        mass[5]++;
        for(int k=5;k>0;k--)
        {
            if(mass[k]==10)
            {
                mass[k-1]+=1;
                mass[k]=0;
            }
        }
    }
    std::cout<<s;
    return 0;
}
