#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int NMAX = 255;

bool ok[2][NMAX][NMAX];

int n, m, p, e, v, cx, cy, r;

struct gheizer
{
  int x1, y1, x2, y2, t, d;
};

ifstream fin("gheizere.in");
ofstream fout("gheizere.out");

vector<gheizer> g;

inline bool inside(int x, int y, int ind)
{
  return g[ind].x1 <= x && g[ind].y1 <= y && g[ind].x2 >= x && g[ind].y2 >= y;
}

bool valid(int k, int x, int y)
{
  for (int i = 0; i < p; ++i)
    if (inside(x, y, i))
    {
      int tot = g[i].t + g[i].d;
      k %= tot;
      if (k >= g[i].t)
        return 0;
    }

  return 1;
}

void refa(int crt, int time)
{
  for (int k = 0; k < p; ++k)
  {
    for (int i = g[k].x1; i <= g[k].x2; ++i)
    {
      for (int j = g[k].y1; j <= g[k].y2; ++j)
      {
        int tt = time % (g[k].t + g[k].d);
        if (tt == 0 || tt > g[k].t)
          ok[crt][i][j] = 0;
      }
    }
  }
}

int main()
{
  fin >> n >> m >> p >> v >> e;

  g.resize(p);

  for (int i = 0; i < p; ++i)
  {
    fin >> cx >> cy >> r >> g[i].t >> g[i].d;
    g[i].x1 = max(cx - r, 1);
    g[i].y1 = max(cy - r, 1);
    g[i].x2 = min(cx + r, n);
    g[i].y2 = min(cy + r, m);
  }

  ok[0][v][0] = 1;

  int ant = 0;

  for (int k = 1; k <= 1000; ++k)
  {
    int crt = (ant ^ 1);

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
      {
        ok[crt][i][j] = max(ok[ant][i - 1][j], max(ok[ant][i][j - 1], ok[ant][i + 1][j]));
      }

    refa(crt, k);

    if (ok[crt][e][m])
    {
      fout << k << "\n";
      return 0;
    }

    ant = crt;
  }

  return 0;
}