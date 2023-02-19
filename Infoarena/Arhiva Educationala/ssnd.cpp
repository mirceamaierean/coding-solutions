#include <fstream>
#include <vector>
#include <bitset>

std::ifstream fin("ssnd.in");
std::ofstream fout("ssnd.out");

const unsigned long long NMAX = 1e6 + 1;
const unsigned long long MOD = 9973;

std::bitset<NMAX> ciur;
std::vector<unsigned long long> pr;

unsigned long long lgput(unsigned long long a, unsigned long long b)
{
    unsigned long long r = 1;
    while (b)
    {
        if (b & 1LL)
            r *= a;
        b >>= 1;
        a *= a;
    }
    return r - 1;
}

void ciuruire()
{
    pr.push_back(2);

    for (unsigned long long i = 4; i < NMAX; i += 2)
        ciur[i] = 1;

    for (unsigned long long i = 3; i < NMAX; i += 2)
        if (ciur[i] == 0)
        {
            pr.push_back(i);
            for (unsigned long long j = 1LL * i * i; j < NMAX; j += i)
                ciur[j] = 1;
        }
}

void solve(unsigned long long n)
{
    unsigned long long ndiv = 1, suma = 1;
    for (size_t i = 0; i < pr.size() && pr[i] * pr[i] <= n; ++i)
    {
        if (n % pr[i] == 0)
        {
            unsigned long long p = 0;
            while (n % pr[i] == 0)
            {
                ++p;
                n /= pr[i];
            }
            if (p)
            {
                ndiv *= (p + 1);
                ndiv %= MOD;
                suma *= (lgput(pr[i], p + 1) / (pr[i] - 1)) % MOD;
                suma %= MOD;
            }
        }
    }
    if (n > 1)
    {
        ndiv *= 2;
        ndiv %= MOD;
        suma *= (lgput(n, 2) / (n - 1)) % MOD;
        suma %= MOD;
    }
    fout << ndiv << " " << suma << "\n";
}

unsigned long long n, t;

int main()
{
    ciuruire();
    fin >> t;
    while (t--)
    {
        fin >> n;
        solve(n);
    }
    fout.close();
    return 0;
}
