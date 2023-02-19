#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("acces.in");
ofstream fout("acces.out");

const int NMAX = 1002;

int dp[NMAX][NMAX], k, n, m, q;
int a[NMAX][NMAX];

int main()
{
  fin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      fin >> a[i][j];

  for (int j = 1; j <= m; ++j)
    dp[1][j] = (a[1][j] == 1) ? 0 : dp[1][j - 1] + 1;

  for (int i = 1; i <= n; ++i)
    dp[i][1] = (a[i][1] == 1) ? 0 : dp[i - 1][1] + 1;

  for (int i = 2; i <= n; ++i)
    for (int j = 2; j <= m; ++j)
      if (a[i][j] == 1)
      {
        if (dp[i - 1][j] == 0 || dp[i][j - 1] == 0)
          dp[i][j] = 0;
        else if (dp[i - 1][j] > 0 && dp[i][j - 1] > 0)
          dp[i][j] = -dp[i - 1][j - 1];
        else
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
      }
      else
      {
        if (dp[i - 1][j] > 0 && dp[i][j - 1] > 0)
          dp[i][j] = 1 + dp[i - 1][j] + dp[i][j - 1] - abs(dp[i - 1][j - 1]);
        else
        {
          if (dp[i - 1][j] > 0)
            dp[i][j] = 1 + dp[i - 1][j];
          else if (dp[i][j - 1] > 0)
            dp[i][j] = 1 + dp[i][j - 1];
          else
            dp[i][j] = 1;
        }
      }

  fin >> q;

  while (q--)
  {
    fin >> n >> m;
    fout << dp[n][m] << "\n";
  }

  return 0;
}