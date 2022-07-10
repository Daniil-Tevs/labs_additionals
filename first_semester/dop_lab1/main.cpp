#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main()
{
    ifstream in("../input.txt");
    ofstream out("output.txt");
    float Q1,P1,Q2,P2,A;
    in>>Q1>>P1>>Q2>>P2>>A;
    int t=A,sum=0,ch=ceil(A/min(Q1,Q2)),s=0;
    int* mass=new int[ch];
    for(int i=0;i<ch;i++)
    {
        A=t;
        s=0;
        sum=i*Q1;
        for(int j=0;j<ch;j++)
        {
            if(sum>=A) { break; }
            s+=1;
            sum=sum+Q2;
        }
        mass[i]=P1*i+s*P2;
    }
    for(int i=0;i<ch;i++)
        out<<mass[i]<<" ";
    for(int i=0;i<ch;i++) {
        for(int j=0;j<ch;j++) {
            if(mass[i]<=mass[j])
                swap(mass[i],mass[j]);
        }
    }
    out<<endl<<mass[0];
    delete[] mass;
    return 0;
}
