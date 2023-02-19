#include <fstream>
#include <vector>
#include <bitset>

std::ifstream fin("iepuri2.in");
std::ofstream fout("iepuri2.out");

const int NMAX = 102;
const int MOD = 30011;
std::vector<int> g[NMAX];

int v[NMAX], dp[NMAX][NMAX], n, k, a, b;

std::bitset<NMAX> leaf;

void solve(int node)
{
  for (int i = 1; i <= k; ++i)
    dp[node][i] = 1;

  for (auto x : g[node])
  {
    solve(x);
    for (int i = 1; i <= k; ++i)
    {
      v[i] = 0;
      for (int j = i + 1; j <= k; ++j)
      {
        v[i] += dp[x][j];
        v[i] %= MOD;
      }
      dp[node][i] *= v[i];
      dp[node][i] %= MOD;
    }
  }
}

int main()
{
  fin >> n >> k;
  for (int i = 1; i < n; ++i)
  {
    fin >> a >> b;
    g[a].push_back(b);
    leaf[b] = 1;
  }

  int s = 0;

  for (int i = 1; i <= n; ++i)
    if (leaf[i] == 0)
    {
      solve(i);
      for (int j = 1; j <= k; ++j)
      {
        s += dp[i][j];
        s %= MOD;
      }
      fout << s << "\n";
      return 0;
    }
  fout.close();
  return 0;
}