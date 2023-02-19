#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("calatorie1.in");
ofstream fout("calatorie1.out");

const int MOD = 997;
const int NMAX = 5 * 10e4;

int d[NMAX], c[30];

int n, k, p;

int main()
{
  fin >> n >> k >> p;

  int a;

  for (int i = 1; i <= p; ++i)
  {
    fin >> a;
    d[a] = -1;
  }

  c[0] = 1;
  k /= 2;
  for (int i = 1; i <= k; ++i)
    for (int j = 0; j < i; ++j)
    {
      c[i] += c[j] * c[i - j - 1];
      c[i] %= MOD;
    }

  d[0] = 1;

  for (int i = 1; i <= n; ++i)
    if (d[i] != -1)
    {
      for (int j = max(0, i - k); j < i; ++j)
        if (d[j] != -1)
        {
          d[i] += 2 * d[j] * c[i - j - 1];
          d[i] %= MOD;
        }
    }

  fout << d[n] << "\n";

  return 0;
}
