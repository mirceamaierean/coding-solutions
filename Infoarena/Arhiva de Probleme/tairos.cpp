#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#include <bitset>

std::ifstream fin("tairos.in");
std::ofstream fout("tairos.out");

int cnt;

const int MOD = 1e9 + 7;
const int NMAX = 1e3 + 1;
const int DMAX = 1e5 + 2;

std::queue<int> q;

std::vector<int> g[NMAX];

std::bitset<NMAX> used;

int n, m, x, y, l_cnt[NMAX], fr[NMAX], nfr[NMAX], ad;

unsigned long long dp[DMAX + NMAX];

void DFS(int node, int l)
{
  used[node] = 1;

  ad = (l > ad) ? l : ad;

  if (node != 1 && g[node].size() == 1)
  {
    ++fr[l];
    return;
  }

  ++nfr[l];
  for (auto i : g[node])
    if (!used[i])
      DFS(i, l + 1);
}

void solve()
{
  dp[0] = 1;
  for (int i = 0; i <= m; ++i)
    for (int j = 1; j <= ad; ++j)
    {
      dp[i + j] += 1LL * dp[i] * fr[j];
      dp[i + j] %= MOD;
    }

  for (int i = 1; i <= std::min(ad, m); ++i)
  {
    dp[m] += 1LL * dp[m - i] * nfr[i];
    dp[m] %= MOD;
  }

  fout << dp[m] << "\n";
}

int main()
{
  fin >> n >> m;
  for (int i = 1; i < n; ++i)
  {
    fin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  DFS(1, 0);

  solve();

  return 0;
}
