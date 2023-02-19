#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string.h>
using namespace std;

const int NMAX = 3005;
const int oo = 0x3f3f3f3f;

int t, n, pi[NMAX], w, m, dp[NMAX];
string s, x;
bitset<NMAX> match[NMAX];

ifstream fin("carte.in");
ofstream fout("carte.out");

void make_prefix()
{
  int k = 0;
  for (int i = 2; i <= m; ++i)
  {
    while (k > 0 && x[k + 1] != x[i])
      k = pi[k];
    if (x[k + 1] == x[i])
      ++k;
    pi[i] = k;
  }
}

void kmp()
{
  int k = 0;
  for (int i = 1; i <= n; ++i)
  {
    while (k > 0 && x[k + 1] != s[i])
      k = pi[k];
    if (x[k + 1] == s[i])
      ++k;
    if (k == m)
    {
      match[i - k + 1][i - k + m] = 1;
      k = pi[k];
    }
  }
}

int main()
{
  fin >> t;
  while (t--)
  {
    fin >> s;
    n = s.size();
    s.insert(s.begin(), 0);
    fin >> w;
    for (int i = 1; i <= w; ++i)
    {
      fin >> x;
      m = x.size();
      x.insert(x.begin(), 0);
      make_prefix();
      kmp();
    }

    memset(dp, oo, sizeof(dp));

    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
      dp[i] = min(dp[i], dp[i - 1] + 1);
      for (int j = 1; j <= i; ++j)
        if (match[j][i])
          dp[i] = min(dp[i], dp[j - 1]);
    }

    fout << dp[n] << '\n';
    for (int i = 1; i <= n; ++i)
      match[i].reset();
  }
  return 0;
}
