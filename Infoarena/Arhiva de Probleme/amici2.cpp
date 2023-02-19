#include <fstream>
#include <queue>
#include <vector>
#include <string.h>
#include <cmath>

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
    int sgn = 1;
    char c;
    while (!isdigit(c = read()) && c != '-')
      ;
    if (c == '-')
    {
      n = 0;
      sgn = -1;
    }
    else
      n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    n *= sgn;
    return *this;
  }
};

InParser fin("amici2.in");
std::ofstream fout("amici2.out");

const int NMAX = 21001;

std::vector<int> g[NMAX];
std::queue<int> q;

int dist[NMAX], max, n, m, t, x, y, deepestNode;

void BFS(int node)
{
  q.push(node);

  memset(dist, 0, sizeof dist);

  max = 0;

  dist[node] = 1;

  while (!q.empty())
  {
    int crt = q.front();

    if (dist[crt] > max)
    {
      max = dist[crt];
      deepestNode = crt;
    }

    q.pop();
    for (auto v : g[crt])
      if (dist[v] == 0)
      {
        dist[v] = dist[crt] + 1;
        q.push(v);
      }
  }
}

int main()
{
  fin >> t;
  while (t--)
  {
    fin >> n >> m;

    for (int i = 1; i <= n; ++i)
      g[i].clear();

    for (int i = 1; i <= m; ++i)
    {
      fin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    BFS(x);

    BFS(deepestNode);

    fout << (int)log2(max) + 1 << "\n";
  }
  fout.close();
  return 0;
}
