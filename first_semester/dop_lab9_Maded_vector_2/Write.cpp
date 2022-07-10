#include <fstream>
#include "class.h"
void Maded_vector::Write()
{
    std::ofstream out("output.txt");
    for(int i=0;i<n;i++)
        out<<mass_vs[n]<<" ";
    out.close();
}
