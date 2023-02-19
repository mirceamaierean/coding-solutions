#include <fstream>
#include <cmath>

using namespace std;

unsigned long long prim(unsigned long long a)
{
    for (unsigned long long i = 2; i <= sqrt(a); ++i)
        if (a % i == 0)
            return i;
    return a;
}

ifstream fin("perechi.in");
ofstream fout("perechi.out");

int main()
{
    unsigned long long a, d = 3, p = 0, cnt = 1;

    fin >> a;

    d = prim(a);

    while (a > 1)
    {
        p = 0;

        while (a % d == 0)
        {
            a /= d;
            ++p;
        }

        cnt *= (2 * p + 1);
        d = prim(a);
        p = 0;
    }

    fout << (cnt + 1) / 2;

    return 0;
}
