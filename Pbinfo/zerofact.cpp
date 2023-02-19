#include <cmath>
int nz(int n)
{
    int nf = 0, cr = 5;
    while (cr < n)
    {
        nf += n / cr;
        cr *= 5;
    }
    return nf;
}