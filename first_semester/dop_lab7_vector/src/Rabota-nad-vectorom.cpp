#include <vector>

namespace dt
{
    bool Digit(int a)
    {
        int sum=0;
        while(a>0)
        {
            sum+=a%10;
            a/=10;
        }
        if(sum%6==0)
            return true;
        else
            return false;
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

void Delete(std::vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
        if(dt::Digit(vec[i]))
        {
            vec.erase(vec.begin()+i);
            i-=1;
        }
}
void Duplication(std::vector<int> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        if(dt::First_Digit(vec[i]))
        {
            vec.insert(vec.begin()+i,vec[i]);
            i+=1;
        }
    }
}