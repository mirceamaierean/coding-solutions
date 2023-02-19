#include <fstream>

using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

long long eul(long long n)
{
    long long r = n, d = 2;
    while (n > 1)
    {
        if (n % d == 0)
        {
            r /= d;
            r *= (d - 1);
            while (n % d == 0)
                n /= d;
        }
        ++d;
        if (d * d > n)
            d = n;
    }
    return r;
}

long long mod;

long long lgput(long long a, long long b)
{
    long long p = 1;
    while (b)
    {
        if (b & 1)
        {
            p *= a;
            p %= mod;
            b--;
        }
        else
        {
            a *= a;
            a %= mod;
            b = b >> 1;
        }
    }
    return p;
}

int main()
{
    long long a, n;
    fin >> a >> n;
    long long phi = eul(n) - 1;
    mod = n;
    fout << lgput(a, phi) << "\n";
    return 0;
}
