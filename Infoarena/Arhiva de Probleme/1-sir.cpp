#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("1-sir.in");
ofstream fout("1-sir.out");

const int NMAX = 100005;
const int MOD = 194767;

int dp[2][NMAX], n, s, ind;

int main()
{
  fin >> n >> s;
  s = abs(s);
  int k = ((n * (n - 1)) >> 1);
  if (s > k)
  {
    fout << "0\n";
    return 0;
  }

  dp[0][0] = 1;
  int p = 1;
  for (int i = 2; i <= n; ++i)
  {
    int ap = (p ^ 1);
    for (int j = 0; j < k; ++j)
    {
      dp[p][j] = dp[ap][j + i - 1] + dp[ap][abs(j - i + 1)];
      if (dp[p][j] >= MOD)
        dp[p][j] -= MOD;
    }
    p = ap;
  }
  p ^= 1;
  fout << dp[p][s] << "\n";
  return 0;
}
