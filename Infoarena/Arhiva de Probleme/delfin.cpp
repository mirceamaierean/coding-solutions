#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

ifstream fin("delfin.in");
ofstream fout("delfin.out");

const int NMAX = 1005;

int n, m, xs, ys, xd, yd, xf, yf, sol;
char viz[NMAX][NMAX];
char mat[NMAX][NMAX];
int dist_s[NMAX][NMAX], dist_f[NMAX][NMAX], dist_d[NMAX][NMAX];

queue<pair<int, int>> q;

inline bool inside(int x, int y)
{
  return x && y && x <= n && y <= m;
}

void lee_d()
{
  q.push({xd, yd});
  dist_d[xd][yd] = 0;
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (inside(nx, ny) && mat[nx][ny] == 0)
      {
        if (dist_d[x][y] + 1 < dist_d[nx][ny])
        {
          dist_d[nx][ny] = dist_d[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }
  }
}

void lee_f()
{
  lee_d();
  q.push({xf, yf});
  dist_f[xf][yf] = 0;
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (inside(nx, ny) && !(mat[x][y] == 0 && mat[nx][ny] == 1))
      {
        if (dist_f[x][y] + 1 < dist_f[nx][ny])
        {
          dist_f[nx][ny] = dist_f[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }
  }
}

void lee()
{
  lee_f();
  q.push({xs, ys});
  dist_s[xs][ys] = 0;
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (inside(nx, ny))
      {
        if (mat[nx][ny] == 1)
        {
          if (dist_s[x][y] + 1 < dist_s[nx][ny])
          {
            q.push({nx, ny});
            dist_s[nx][ny] = dist_s[x][y] + 1;
          }
        }
        else
          sol = min(sol, max(dist_s[x][y] + 1, dist_d[nx][ny]) + dist_f[nx][ny]);
      }
    }
  }
  sol = min(sol, dist_s[xf][yf]);
  fout << sol << "\n";
}
int main()
{
  sol = NMAX * NMAX;
  fin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
      char ch;
      fin >> ch;
      if (ch == 'S')
      {
        xs = i;
        ys = j;
        mat[i][j] = 1;
      }
      else if (ch == 'D')
      {
        xd = i;
        yd = j;
      }
      else if (ch == 'F')
      {
        xf = i;
        yf = j;
        mat[i][j] = 1;
      }
      else
        mat[i][j] = ch - '0';
      dist_s[i][j] = NMAX * NMAX;
      dist_f[i][j] = NMAX * NMAX;
      dist_d[i][j] = NMAX * NMAX;
    }
  lee();
  return 0;
}
