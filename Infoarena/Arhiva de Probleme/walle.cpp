#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <vector>
#define x first
#define y second
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

typedef pair<int, int> p;

const int NMAX = 502;
const int oo = 0x3f3f3f;

int d[2][NMAX][NMAX], ind;

bool viz[2][NMAX][NMAX];

struct cmp
{
  bool operator()(p a, p b)
  {
    return d[ind][a.x][a.y] > d[ind][b.x][b.y];
  }
};

priority_queue<p, vector<p>, cmp> q;
char a[NMAX][NMAX];
int n, m, t, maxi1, maxi2, mini;
p w, e, k;

inline bool ok(int x, int y)
{
  return x && y && x <= n && y <= m && viz[ind][x][y] == 0 && a[x][y] != '#';
}

vector<p> port;

int nou(int x, int y)
{
  int cost = oo;
  for (int i = 0; i < 4; ++i)
  {
    char v = a[x + dx[i]][y + dy[i]];
    if (v == '+')
      cost = t + 2;
    else if (v == '.')
      return 2;
  }
  return cost;
}

void solve()
{
  p c;
  while (!q.empty())
  {
    int time = 1;

    do
    {
      c = q.top();
      q.pop();
    } while (!q.empty() && viz[ind][c.x][c.y] == 1);

    viz[ind][c.x][c.y] = 1;
    if (a[c.x][c.y] == '+')
      time += t;

    int val = d[ind][c.x][c.y] + time;

    for (int i = 0; i < 4; ++i)
    {
      int nx = c.x + dx[i];
      int ny = c.y + dy[i];

      if (ok(nx, ny) && val < d[ind][nx][ny])
      {
        d[ind][nx][ny] = val;
        if (a[nx][ny] == '.' || a[nx][ny] == '+')
          q.push({nx, ny});
      }
    }
  }
}

void final()
{
  for (size_t i = 0; i < port.size(); ++i)
  {
    int x = port[i].x, y = port[i].y;
    if (d[0][x][y] > maxi1)
    {
      k = port[i];
      maxi2 = maxi1;
      maxi1 = d[0][x][y];
    }
    else if (d[0][x][y] > maxi2)
      maxi2 = d[0][x][y];
  }

  for (size_t i = 0; i < port.size(); ++i)
  {
    if (port[i] == k)
    {
      if (d[1][port[i].x][port[i].y] + maxi2 < mini)
        mini = d[1][port[i].x][port[i].y] + maxi2;
    }
    else if (d[1][port[i].x][port[i].y] + maxi1 < mini)
      mini = d[1][port[i].x][port[i].y] + maxi1;
  }
}

int main()
{
  FILE *fin = fopen("walle.in", "rt"), *fout = fopen("walle.out", "wt");

  fscanf(fin, "%d", &n);
  fscanf(fin, "%d", &m);
  fscanf(fin, "%d", &t);

  fgetc(fin);

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      d[0][i][j] = oo;
      d[1][i][j] = oo;
      a[i][j] = fgetc(fin);
      if (a[i][j] == 'P')
        port.push_back({i, j});
      else if (a[i][j] == 'E')
        e = {i, j};
      else if (a[i][j] == 'W')
        w = {i, j};
    }
    fgetc(fin);
  }

  d[0][e.x][e.y] = 0;
  viz[0][e.x][e.y] = 1;
  d[1][w.x][w.y] = 0;
  viz[1][w.x][w.y] = 1;

  q.push(e);

  solve();

  ind = 1;

  q.push(w);
  solve();

  mini = d[0][w.x][w.y];

  final();

  for (size_t i = 0; i < port.size(); ++i)
  {
    int crt = nou(port[i].x, port[i].y) + ((d[0][port[i].x][port[i].y] == maxi1) ? maxi2 : maxi1);
    if (crt < d[0][port[i].x][port[i].y])
      d[0][port[i].x][port[i].y] = crt;
  }

  maxi1 = 0;
  maxi2 = 0;

  final();

  if (mini == oo)
    mini = -1;

  fprintf(fout, "%d", mini);

  return 0;
}