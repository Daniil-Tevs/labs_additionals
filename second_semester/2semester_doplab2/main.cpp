#include <iostream>
#include <vector>
#include <fstream>
int key(int a)
{
    return a;
}
void COUNTSORT(int n,int m,std::vector<int> &x)
{
    std::vector<int> c;
    int k,i=0;
    for(int i=0;i<m;i++)
        c.push_back(0);
    for(int j=0;j<n;j++)
    {
        k = key(x[j]);
        c[k]=c[k]+1;
    }
    for(int j=0;j<m;j++)
    {
        while(c[j]>0)
        {
            x[i] = j;
            c[j]--;
            i++;
        }
    }
}
int main() {
    std::ofstream out("../output.txt");
    std::vector<int> basic;
    int N,max=INT32_MIN;
    std::cin>>N;
    for(int i=0;i<N;i++) {
        basic.push_back(5 + rand() % 100);
        max=std::max(max,basic[i]);
        out<<basic[i]<<" ";
    }
    out<<"\n";
    COUNTSORT(N,max+1,basic);
    for(int i=0;i<N;i++)
        out<<basic[i]<<" ";
    return 0;
}
