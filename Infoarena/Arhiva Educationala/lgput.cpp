#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

unsigned long long rl(unsigned long long n, unsigned long long p)
{
    n %= 1999999973;
    unsigned long long nr = 1;
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            nr = (nr * n) % 1999999973;
            p--;
        }
        else
        {
            n = (n * n) % 1999999973;
            p = p / 2;
        }
    }
    return nr;
}

ifstream fin("lgput.in");
ofstream fout("lgput.out");

int main()
{
    int a, b;
    fin >> a >> b;
    fout << rl(a, b);

    return 0;
}
