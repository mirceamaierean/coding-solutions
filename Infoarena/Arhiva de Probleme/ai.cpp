#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<int, int>> q;

int __gcd(int a, int b)
{
  if (b == 0)
    return a;
  a %= b;
  return __gcd(b, a);
}

class InParser
{
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
    fin = fopen(nume, "r");
    sp = 4095;
    buff = new char[4096];
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

InParser fin("ai.in");
ofstream fout("ai.out");

const int NMAX = 1005;

int a[NMAX][NMAX], col[NMAX], lin[NMAX], ans;
int n, x, y, k, tx, ty, sx1, sx2, sy1, sy2, rx[2], ry[2], mini[2][2];

int ind;
int lee_dist[2][NMAX][NMAX];

inline bool diferit(int x, int y)
{
  return x == rx[ind] && y == ry[ind];
}

inline bool ok(int x, int y)
{
  return x && y && x <= n && y <= n && lee_dist[ind][x][y] == 0 && (x != tx || y != ty) && !diferit(x, y) && a[x][y] < 3;
}
void lee()
{
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ok(nx, ny))
      {
        lee_dist[ind][nx][ny] = lee_dist[ind][x][y] + 1;
        if (a[nx][ny] == 1)
          mini[ind][0] = min(mini[ind][0], lee_dist[ind][nx][ny]);
        if (a[nx][ny] == 2)
          mini[ind][1] = min(mini[ind][1], lee_dist[ind][nx][ny]);
        q.push({nx, ny});
      }
    }
  }
}

int main()
{
  mini[0][0] = NMAX * NMAX;
  mini[1][0] = NMAX * NMAX;
  mini[0][1] = NMAX * NMAX;
  mini[1][1] = NMAX * NMAX;
  fin >> n >> tx >> ty >> sx1 >> sy1 >> sx2 >> sy2 >> rx[0] >> ry[0] >> rx[1] >> ry[1] >> k;

  x = abs(tx - sx1);
  y = abs(ty - sy1);

  if (x == 0)
  {
    x = 0;
    y = 1;
  }
  else if (y == 0)
  {
    x = 1;
    y = 0;
  }

  else
  {
    int g = __gcd(x, y);
    x /= g;
    y /= g;
  }
  int fx = sx1, fy = sy1;
  if (sx1 > tx)
    x = -x;
  if (sy1 > ty)
    y = -y;

  while (fx != tx || fy != ty)
  {
    a[fx][fy] = 1;
    if (fx == rx[0] && fy == ry[0])
      mini[1][0] = 0;
    if (fx == rx[1] && fy == ry[1])
      mini[1][1] = 0;
    fx += x;
    fy += y;
  }

  x = abs(tx - sx2);
  y = abs(ty - sy2);

  if (x == 0)
  {
    x = 0;
    y = 1;
  }
  else if (y == 0)
  {
    x = 1;
    y = 0;
  }

  else
  {
    int g = __gcd(x, y);
    x /= g;
    y /= g;
  }
  fx = sx2;
  fy = sy2;

  if (sx2 > tx)
    x = -x;
  if (sy2 > ty)
    y = -y;

  while (fx != tx || fy != ty)
  {
    a[fx][fy] = 2;
    if (fx == rx[0] && fy == ry[0])
      mini[1][0] = 0;
    if (fx == rx[1] && fy == ry[1])
      mini[1][1] = 0;
    fx += x;
    fy += y;
  }

  while (k--)
  {
    fin >> x >> y;
    a[x][y] = 3;
  }

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    {
      if (a[i][j] != 3)
      {
        col[j] = 0;
        lin[i] = 0;
      }
      else
      {
        col[j]++;
        lin[i]++;
      }
      ans = max(col[j], ans);
      ans = max(lin[i], ans);
    }

  fout << ans << "\n";

  q.push({rx[0], ry[0]});
  lee();
  ind = 1;
  q.push({rx[1], ry[1]});
  lee();

  ans = 0;

  ans = max(mini[0][0], mini[1][1]);
  ans = min(ans, max(mini[0][1], mini[1][0]));
  ans = min(ans, max(mini[1][1], mini[0][0]));
  fout << ans << "\n";

  return 0;
}