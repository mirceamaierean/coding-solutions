#include <fstream>
#include <string.h>
using namespace std;

ifstream fin("margiki.in");
ofstream fout("margiki.out");

const int MOD = 1000000007;

long long p[3][3], q[3][3], r[3][3], x, y, z, n;

void exp_mat()
{
  p[0][1] = p[1][2] = 1;
  p[0][0] = 1;
  p[1][0] = 1;
  p[2][0] = 1;

  q[0][0] = q[1][1] = q[2][2] = 1;

  n -= 3;

  while (n)
  {
    if (n & 1)
    {
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
          r[i][j] = 0;
          for (int l = 0; l < 3; ++l)
          {
            r[i][j] += q[i][l] * p[l][j];
            r[i][j] %= MOD;
          }
        }
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
          q[i][j] = r[i][j];
    }
    n >>= 1;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
      {
        r[i][j] = 0;
        for (int l = 0; l < 3; ++l)
        {
          r[i][j] += p[i][l] * p[l][j];
          r[i][j] %= MOD;
        }
      }
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        p[i][j] = r[i][j];
  }
  long long val = 1LL * z * q[0][0] + 1LL * y * q[1][0] + 1LL * x * q[2][0];
  fout << val % MOD << "\n";
}

int main()
{
  fin >> n;
  x = 1;
  y = 2;
  z = 4;
  if (n == 1)
    fout << x << "\n";
  else if (n == 2)
    fout << y << "\n";
  else if (n == 3)
    fout << z << '\n';
  else
    exp_mat();
  fout.close();
  return 0;
}
