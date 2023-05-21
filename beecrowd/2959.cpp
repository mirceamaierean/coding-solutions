#include <iostream>
#include <string.h>
#include <vector>
#define NMAX 401
using namespace std;
vector<int> v[NMAX];
bool dr[NMAX][NMAX], viz[NMAX];
int n, m, q, a, b, key;
void DFS(int x)
{
  dr[x][key] = 1;
  dr[key][x] = 1;
  viz[x] = 1;
  for (size_t i = 0; i < v[x].size(); ++i)
    if (viz[v[x][i]] == 0)
      DFS(v[x][i]);
}
void solve()
{
  cin >> n >> m >> q;
  for (int i = 1; i <= m; ++i)
  {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i)
  {
    memset(viz, 0, sizeof viz);
    key = i;
    DFS(i);
  }
  for (int i = 1; i <= q; ++i)
  {
    cin >> a >> b;
    if (dr[a][b])
      cout << "Lets que lets\n";
    else
      cout << "Deu ruim\n";
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
