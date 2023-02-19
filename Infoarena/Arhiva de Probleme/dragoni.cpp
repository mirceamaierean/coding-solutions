#include <fstream>
#include <queue>
#include <bitset>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

class InParser
{
#pragma warning(disable : 4996)
private:
  FILE *fin;
  char *buff;
  int sp;
  char read()
  {
    ++sp;
    if (sp == 4096)
    {
      sp = 0;
      fread(buff, 1, 4096, fin);
    }
    return buff[sp];
  }

public:
  InParser(const char *nume)
  {
    sp = 4095;
    buff = new char[4096];
    fin = fopen(nume, "r");
  }
  InParser &operator>>(int &n)
  {
    char c;
    while (!isdigit(c = read()))
      ;
    n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    return *this;
  }
};

InParser fin("dragoni.in");
ofstream fout("dragoni.out");

typedef pair<int, int> p;

const int NMAX = 803;
const int oo = 0x3f3f3f3f;
int dr[NMAX], c, n, m, ind_maxi, dist[NMAX][NMAX], a, b, d; // dist[i][j] = distanta minima sa ajung pe insula i cu un dragon de tip j

vector<p> g[NMAX];

void BFS()
{
  ind_maxi = 1;
  queue<int> q;
  q.push(1);
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    dist[x][1] = 1;
    for (size_t i = 0; i < g[x].size(); ++i)
    {
      int y = g[x][i].first;
      d = g[x][i].second;
      if (dr[1] >= d)
      {
        if (dr[y] > dr[ind_maxi])
          ind_maxi = y;
        if (dist[y][1] == 0)
          q.push(y);
      }
    }
  }
  fout << dr[ind_maxi] << "\n";
}

struct cmp
{
  inline bool operator()(p a, p b)
  {
    return dist[a.first][a.second] > dist[b.first][b.second];
  }
};

void Dijkstra()
{
  priority_queue<p, vector<p>, cmp> q;

  int mini = oo;

  memset(dist, oo, sizeof dist);

  q.push({1, 1});
  dist[1][1] = 0;

  int x, drag;

  while (!q.empty())
  {
    x = q.top().first;
    drag = q.top().second;
    q.pop();

    d = dist[x][drag];
    if (dr[x] > dr[drag])
      drag = x;

    for (size_t i = 0; i < g[x].size(); ++i)
    {
      int y = g[x][i].first, d1 = g[x][i].second;
      if (dr[drag] >= d1 && d + d1 <= dist[y][drag])
      {
        dist[y][drag] = d + d1;
        q.push({y, drag});
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    mini = min(dist[n][i], mini);
  fout << mini << "\n";
}

int main()
{
  fin >> c >> n >> m;
  for (int i = 1; i <= n; ++i)
    fin >> dr[i];

  for (int i = 1; i <= m; ++i)
  {
    fin >> a >> b >> d;
    g[a].push_back({b, d});
    g[b].push_back({a, d});
  }

  if (c == 1)
    BFS();

  else
    Dijkstra();
  fout.close();
  return 0;
}
