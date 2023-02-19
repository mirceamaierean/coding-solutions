#include <fstream>

using namespace std;

ifstream fin("hagi.in");
ofstream fout("hagi.out");

const long long MOD = 1000000007;
const int NMAX = 2 * 1e6 + 2;

long long k, n, m;

long long fact[NMAX];

long long lgput(long long a, long long b)
{
  long long r = 1;
  while (b)
  {
    if (b & 1LL)
    {
      r *= a;
      r %= MOD;
      --b;
    }
    else
    {
      a *= a;
      a %= MOD;
      b >>= 1LL;
    }
  }
  return r;
}

long long comb(long long a, long long b)
{
  return (((fact[a] * lgput(fact[b], MOD - 2)) % MOD) * lgput(fact[a - b], MOD - 2)) % MOD;
}

int main()
{
  fin >> k >> n >> m;

  fact[0] = 1;

  for (int i = 1; i < NMAX; ++i)
    fact[i] = (fact[i - 1] * 1LL * i) % MOD;

  long long r = comb(n + k - 1, k - 1);

  r *= comb(m + k - 1, k - 1);
  r %= MOD;
  fout << r << "\n";

  return 0;
}
