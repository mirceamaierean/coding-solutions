#include <fstream>

using namespace std;

ifstream fin("functii.in");
ofstream fout("functii.out");

const int NMAX = 1e4 + 2;
const int MOD = 30103;

int f[NMAX], n, k;

inline int lgput(int a, int b)
{
  int rez = 1;
  while (b)
  {
    if (b & 1)
    {
      rez *= a;
      rez %= MOD;
      --b;
    }
    else
    {
      a *= a;
      a %= MOD;
      b >>= 1;
    }
  }
  return rez;
}

int main()
{
  fin >> n >> k;
  f[0] = 1;
  for (int i = 1; i <= n; ++i)
    f[i] = (f[i - 1] * i) % MOD;

  fout << ((lgput(2, k) - 2) * ((f[n] * lgput(f[n - k], MOD - 2)) % MOD * lgput(f[k], MOD - 2) % MOD)) % MOD;

  return 0;
}
