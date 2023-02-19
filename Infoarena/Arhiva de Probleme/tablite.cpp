#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream fin("tablite.in");
std::ofstream fout("tablite.out");

const int NMAX = 1e3 + 2;
const int MOD = 60106;

int dp[2][NMAX][10], n, s;
std::vector<int> v[10];

int main()
{
  fin >> n >> s;

  for (int i = 1; i <= 9; ++i)
    dp[0][i][i] = 1;

  for (int i = 0; i <= 1; ++i)
    for (int j = 0; j <= 9; ++j)
      v[i].push_back(j);

  for (int i = 2; i <= 9; ++i)
  {
    v[i].push_back(0);
    v[i].push_back(1);
    for (int j = 2; j <= 9; ++j)
      if (i % j && j % i)
        v[i].push_back(j);
  }

  for (int i = 1; i < n; ++i)
    for (int j = 1; j <= s; ++j)
      for (int k = 0; k <= std::min(j, 9); ++k)
      {
        int ind = i & 1;
        int _ind = 1 - ind;
        dp[ind][j][k] = 0;
        for (auto l : v[k])
        {
          dp[ind][j][k] += dp[_ind][j - k][l];
          if (dp[ind][j][k] >= MOD)
            dp[ind][j][k] -= MOD;
        }
      }

  int sum(0);

  --n;

  for (int i = 0; i <= 9; ++i)
  {
    sum += dp[n & 1][s][i];
    if (sum >= MOD)
      sum -= MOD;
  }

  fout << sum << '\n';

  fout.close();
  return 0;
}