#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;

ifstream fin("joc13.in");
ofstream fout("joc13.out");

const int NMAX = 5001;

int dp[2][NMAX][11], n, a[2][NMAX], k;

int solve()
{
  int maxi = -0x3f3f3f;

  for (int j = 2; j <= n; ++j)
    for (int i = 0; i < 2; ++i)
    {
      for (int l = 2; l <= k; ++l)
        dp[i][j][1] = max(dp[i][j][1], a[i][j] + dp[1 - i][j][l]);

      for (int l = 2; l <= k; ++l)
      {
        if (j - l >= 0)
          dp[i][j][l] = dp[i][j - 1][l - 1] + a[i][j];
      }

      for (int l = 2; l <= k; ++l)
        dp[1 - i][j][1] = max(dp[1 - i][j][1], a[1 - i][j] + dp[i][j][l]);
    }

  for (int i = 1; i <= k; ++i)
    if (dp[1][n][i] > maxi)
      maxi = dp[1][n][i];

  return maxi;
}

const int oo = 0x3f3f3f;

int main()
{
  fin >> n >> k;
  for (int i = 0; i < 2; ++i)
    for (int j = 1; j <= n; ++j)
    {
      fin >> a[i][j];
      for (int l = 1; l <= k; ++l)
        dp[i][j][l] = -oo;
    }

  dp[0][1][1] = a[0][1];
  dp[1][1][1] = a[0][1] + a[1][1];

  fout << solve() << "\n";

  fout.close();
  return 0;
}