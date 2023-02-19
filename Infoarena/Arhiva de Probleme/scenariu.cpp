#include <fstream>

using namespace std;

ifstream fin("scenariu.in");
ofstream fout("scenariu.out");

int n, k, s, a;

const int NMAX = 1e4 + 2;
const int MOD = 666013;
long long fact[NMAX];

inline long long lgput(long long x, long long y)
{
  long long r = 1;
  while (y)
  {
    if (y & 1)
    {
      r *= 1LL * x;
      r %= MOD;
    }
    x *= x;
    x %= MOD;
    y >>= 1;
  }
  return r;
}

int main()
{
  fact[0] = 1;
  fact[1] = 1;
  fin >> n >> k;

  for (int i = 2; i < NMAX; ++i)
  {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }

  for (int i = 1; i <= k; ++i)
  {
    fin >> a;
    s += a;
  }

  fout << (((1LL * fact[n - 1] * lgput(fact[s - 1], MOD - 2)) % MOD) * lgput(fact[n - s], MOD - 2)) % MOD << "\n";
  fout.close();
  return 0;
}
