#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("maxd.in");
ofstream fout("maxd.out");

int a, b, minim, nrdiv, contor;

inline int prim(int n)
{
    int div = 1, d = 2, p = 0;
    while (n > 1)
    {
        p = 0;
        while (n % d == 0)
        {
            n /= d;
            ++p;
        }
        ++p;
        div *= p;
        ++d;
        if (n > 1 && d * d > n)
            d = n;
    }
    return div;
}
int main()
{
    fin >> a >> b;
    for (int i = b; i >= a; i -= 2)
    {
        int val = prim(i);
        if (val > nrdiv)
        {
            nrdiv = val;
            minim = i;
            contor = 0;
        }
        if (val == nrdiv)
        {
            ++contor;
            minim = i;
        }
        if (i % 2 != 0)
            ++i;
    }
    fout << minim << " " << nrdiv << " " << contor;
    return 0;
}
