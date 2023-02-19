#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#define NMAX 1000001

using namespace std;

ifstream cin("berarii2.in");
ofstream cout("berarii2.out");

vector<int> g[NMAX];
bitset<NMAX> ber;

int n, m, p;
int cnt;

void BFS(int x)
{
  bitset<NMAX> viz;
  viz.reset();
  queue<int> q;
  q.push(x);
  while (!q.empty())
  {
    int f = q.front();
    q.pop();
    if (ber[x] == 0)
    {
      cnt--;
      ber[x] = 1;
    }
    viz[x] = 1;
    for (size_t i = 0; i < g[f].size(); ++i)
    {
      if (ber[g[f][i]] == 0)
      {
        cnt--;
        ber[g[f][i]] = 1;
      }
      if (viz[g[f][i]] == 0)
      {
        q.push(g[f][i]);
        viz[g[f][i]] = 1;
        ber[g[f][i]] = 1;
      }
    }
  }
}

void solve()
{
  int x, y;
  cin >> n >> m >> p;
  cnt = n;
  for (int i = 1; i <= m; ++i)
  {
    cin >> x >> y;
    g[y].push_back(x);
  }
  for (int i = 1; i <= p; ++i)
  {
    cin >> x;
    BFS(x);
  }
  cout << cnt << "\n";
  for (int i = 1; i <= n; ++i)
    if (ber[i] == 0)
      cout << i << "\n";
}

int main()
{
  solve();
  return 0;
}