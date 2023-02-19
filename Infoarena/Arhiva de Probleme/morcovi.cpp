#include <fstream>
#include <algorithm>
using namespace std;

const int MASK = (1 << 12) + 1;
const int NMAX = 1003;

ifstream fin("morcovi.in");
ofstream fout("morcovi.out");

int dp[MASK][NMAX], a[NMAX], n, p, pas[15], s;

void read()
{
  fin >> n;

  for (int i = 0; i < n; ++i)
  {
    fin >> a[i];
    dp[0][i] = a[i];
  }

  fin >> p;

  for (int i = 0; i < p; ++i)
    fin >> pas[i];
}

void solve()
{
  // dp[i][j] - gradul maxim de satisfactie daca Rila face pasii din configuratia i si se opreste in j

  int m = (1 << p) - 1;

  for (int mask = 1; mask <= m; ++mask)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < p; ++j)
      {
        int val = 1 << j;
        if (mask & val)
        {
          if (i - pas[j] >= 0)
            dp[mask][i] = max(dp[mask][i], dp[mask - val][i - pas[j]] + a[i]);
          if (i + pas[j] < n)
            dp[mask][i] = max(dp[mask][i], dp[mask - val][i + pas[j]] + a[i]);
        }
      }

  for (int i = 0; i < n; ++i)
    s = max(s, dp[m][i]);
  fout << s << "\n";
}

int main()
{
  read();
  solve();
  return 0;
}