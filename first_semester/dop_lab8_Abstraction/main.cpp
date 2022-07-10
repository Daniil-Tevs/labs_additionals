#include "functions.h"
#include "class.h"
int main()
{
    int dlina=Read();
    EqualTriangle shape{dlina};
    shape.Write();
    return 0;
}
