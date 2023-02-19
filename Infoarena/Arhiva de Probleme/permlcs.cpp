#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

ifstream fin("permlcs.in");
ofstream fout("permlcs.out");

const int NMAX = 1001;

vector<int> v[NMAX];

int norm[NMAX], n, a[NMAX], m, maxi, dp[NMAX];

bitset<NMAX> viz[NMAX];

void DFS(int nod, int cnt)
{
  cnt++;

  dp[nod] = cnt;

  if (cnt > maxi)
    maxi = cnt;

  for (auto i : v[nod])
  {
    if (cnt >= dp[i])
      DFS(i, cnt);
  }
}

int main()
{
  fin >> n >> m;
  for (int i = 1; i <= n; ++i)
  {
    fin >> a[i];
    norm[a[i]] = i;
  }

  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      viz[i][j] = 1;

  for (int j = 2; j <= m; ++j)
  {
    for (int i = 1; i <= n; ++i)
      fin >> a[i];

    for (int i = 1; i <= n; ++i)
      for (int k = i + 1; k <= n; ++k)
        if (norm[a[i]] > norm[a[k]])
          viz[norm[a[k]]][norm[a[i]]] = 0;
  }

  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (viz[i][j])
        v[i].push_back(j);

  for (int i = 1; i <= n; ++i)
    if (viz[i][0] == 0)
      DFS(i, 0);

  fout << maxi << "\n";

  fout.close();
  return 0;
}