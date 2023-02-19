#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <queue>

std::ifstream fin("marmelada.in");
std::ofstream fout("marmelada.out");

const int NMAX = 1e5 + 1;

typedef std::pair<int, int> p;

std::vector<p> g[NMAX];
std::vector<p> t;

void BFS(int startingNode)
{
  std::queue<int> q;
  q.push(startingNode);

  while (!q.empty())
  {
    int x = q.front();
    q.pop();

    for (auto i : g[x])
      if (t[i.first].first == 0 && i.first != startingNode)
      {
        q.push(i.first);
        t[i.first] = {x, i.second};
      }
  }
}

int n, m, s, d, x, y;

std::priority_queue<p, std::vector<p>, std::greater<p>> c;

int main()
{
  fin >> n >> m >> s >> d;

  std::vector<int> C(m + 1, 0);

  t.resize(n + 1);

  for (int i = 1; i <= m; ++i)
  {
    fin >> x >> y;
    g[x].push_back({y, i});
    g[y].push_back({x, i});
  }

  for (int i = 1; i <= m; ++i)
  {
    fin >> x;
    c.push({x, i});
  }

  BFS(s);

  while (t[d].first != 0)
  {
    C[t[d].second] = c.top().second;
    c.pop();
    d = t[d].first;
  }

  for (int i = 1; i <= m; ++i)
    if (C[i])
      fout << C[i] << "\n";
    else
    {
      fout << c.top().second << "\n";
      c.pop();
    }

  fout.close();
  return 0;
}