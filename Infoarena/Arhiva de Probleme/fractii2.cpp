#include <fstream>

std::ifstream fin("fractii2.in");
std::ofstream fout("fractii2.out");

const int MOD = 100003;

const int NMAX = 1e3 + 5;

int p, n, dp[2 * NMAX][NMAX];

int main()
{
  fin >> p >> n;

  if (p == 1)
  {
    for (int i = 1; i < n; ++i)
      fout << i << " ";

    fout << n - 1 << "\n";
  }

  else
  {
    dp[2][1] = 1;
    for (int i = 3; i <= n; ++i)
    {
      int m = (i >> 1);
      for (int j = 1; j <= m; j++)
      {
        int st = i - j, s = (j + 1) / 2 - 1, d = (i - j) / 2;

        dp[i][j] = dp[i][j - 1] + dp[i - j][d] - dp[i - j][s];

        if (dp[i][j] < 0)
          dp[i][j] += MOD;

        if (dp[i][j] >= MOD)
          dp[i][j] -= MOD;
      }
    }

    fout << dp[n][n / 2] << "\n";
  }

  fout.close();
  return 0;
}
