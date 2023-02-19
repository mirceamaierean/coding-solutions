#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("gaz.in");
ofstream fout("gaz.out");

const long long oo = 0x3f3f3f3f3f3f;
const int NMAX = 2005;
int l, p, d, c, n;
int g[NMAX];

long long dp[NMAX];

int main()
{
  fin >> l >> p >> d >> c >> n;
  for (int i = 1; i <= n; ++i)
    fin >> g[i];

  for (int i = 1; i <= n; ++i)
  {
    dp[i] = oo;
    int c_g = 0;
    long long c_p = 0;
    for (int j = i - 1; j >= 0; --j)
    {
      if (c_g > l)
        c_p += (1LL * c * (c_g - l));
      c_g += g[j + 1];
      dp[i] = min(dp[i], dp[j] + p + c_p + 1LL * d * c_g);
    }
  }
  fout << dp[n];
  return 0;
}