#include <fstream>

using namespace std;

const int MOD = 9901;

long long lgput(long long a, long long b)
{
    long long r = 1;
    a %= MOD;
    while (b)
    {
        if (b & 1LL)
        {
            --b;
            r *= a;
            r %= MOD;
        }
        else
        {
            b >>= 1LL;
            a *= a;
            a %= MOD;
        }
    }
    return r;
}

long long suma(long long a, long long b)
{
    if (a == 0)
        return 1;
    if (a == 1)
        return (b + 1) % MOD;
    return (lgput(a, b + 1) + MOD - 1) % MOD * lgput(a - 1, MOD - 2) % MOD;
}

long long a, b, r, p, d, t1, t2;

ifstream fin("sumdiv.in");
ofstream fout("sumdiv.out");

int main()
{
    r = 1;

    fin >> a >> b;

    while ((a & 1LL) == 0)
    {
        d += b;
        a >>= 1LL;
    }

    if (d)
    {
        ++d;
        r = (lgput(2, d) - 1) % MOD;
    }

    p = 3;

    while (a > 1 && p * p <= a)
    {
        d = 0;
        while (a % p == 0)
        {
            a /= p;
            d += b;
        }
        if (d)
        {
            r *= suma(p % MOD, d);
            r %= MOD;
        }
        p += 2;
    }

    if (a > 1)
    {
        r *= suma(a % MOD, b);
        r %= MOD;
    }

    fout << r << "\n";

    return 0;
}
