#include <fstream>
using namespace std;

ifstream fin("2sah.in");
ofstream fout("2sah.out");

long long t, n, k, a[3][3], b[3][3], c[3][3];
const long long MOD = 100003;

long long lgput(long long a, long long b)
{
  long long r = 1;
  while (b)
  {
    if (b & 1LL)
    {
      r *= a;
      r %= MOD;
    }
    a *= a;
    a %= MOD;
    b >>= 1LL;
  }
  return r;
}

void expmat()
{
  k = n + 2 - k;

  a[0][1] = a[1][2] = 1;

  for (int i = 0; i < 3; ++i)
    a[2][i] = b[i][i] = 1;

  while (k)
  {
    if (k & 1)
    {
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
          c[i][j] = 0;
          for (int l = 0; l < 3; ++l)
          {
            c[i][j] += b[i][l] * a[l][j];
            c[i][j] %= MOD;
          }
        }
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
          b[i][j] = c[i][j];
    }
    k >>= 1;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
      {
        c[i][j] = 0;
        for (int l = 0; l < 3; ++l)
        {
          c[i][j] += a[i][l] * a[l][j];
          c[i][j] %= MOD;
        }
      }
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        a[i][j] = c[i][j];
  }
  fout << b[1][2] << "\n";
}

int main()
{
  fin >> t >> n >> k;
  if (t == 1)
    fout << lgput(3, k - 1) << "\n";
  else
    expmat();
  fout.close();
  return 0;
}
