#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

ifstream fin("stiva.in");
ofstream fout("stiva.out");

const int NMAX = 505;

int dp[NMAX][NMAX];

string a;
int mini;

int main()
{
  fin >> a;

  int l = a.size();

  for (int i = 0; i < l; ++i)
    dp[i][i] = 1;

  for (int d = 1; d < l; ++d)
  {
    for (int i = 0; i < l - d; ++i)
    {
      int j = i + d;
      dp[i][j] = dp[i][j - 1] + 1;
      for (int k = i; k < j; ++k)
        if (a[k] == a[j] && dp[i][k] + dp[k + 1][j - 1] < dp[i][j])
          dp[i][j] = dp[i][k] + dp[k + 1][j - 1];
    }
  }

  fout << 2 * dp[0][l - 1] + l << "\n";

  return 0;
}