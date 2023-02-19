#include <fstream>

using namespace std;

const int NMAX = 5003;
const int MOD = 666013;

ifstream fin("100m.in");
ofstream fout("100m.out");

long long i, j, n, H, a[NMAX], b[NMAX], f;

int main()
{
  fin >> n;

  a[0] = b[0] = f = 1;

  for (i = 1; i < n; ++i)
  {
    for (j = 1; j <= i; ++j)
      b[j] = ((j + 1LL) * a[j] + a[j - 1]) % MOD;

    for (j = 0; j <= i; ++j)
      a[j] = b[j];
  }

  for (int i = 1; i <= n; ++i)
  {
    H += (b[i - 1] * f);
    H %= MOD;
    f *= 1LL * (i + 1LL);
    f %= MOD;
  }

  fout << H << "\n";
  return 0;
}
