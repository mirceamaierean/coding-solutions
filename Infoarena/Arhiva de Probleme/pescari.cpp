#include <fstream>
#include <iostream>
#include <string.h>
#include <queue>
#pragma warning(disable : 4996)
using namespace std;

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 0, 1, -1};

ifstream fin("pescari.in");
ofstream fout("pescari.out");

queue<pair<int, int>> q;
queue<pair<int, int>> pescari;

const int NMAX = 1005;

int a[NMAX][NMAX];
int n, m, p;

int d[NMAX][NMAX];
char viz[NMAX][NMAX];

inline bool ok(int x, int y)
{
  return x && y && x <= n && y <= m && d[x][y] == 0 && viz[x][y] == 0;
}

void Lee()
{
  while (!q.empty())
  {
    int x = q.front().first, y = q.front().second;
    viz[x][y] = 1;
    q.pop();
    for (int i = 0; i < 8; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ok(nx, ny))
      {
        d[nx][ny] = d[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
}

int main()
{
  fin >> n >> m >> p;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
      fin >> a[i][j];
      if (a[i][j] == 2)
      {
        viz[i][j] = 1;
        q.push({i, j});
      }
      else if (a[i][j] == 1)
        pescari.push({i, j});
    }

  Lee();

  while (!pescari.empty())
  {
    int x = pescari.front().first;
    int y = pescari.front().second;
    pescari.pop();
    fout << d[x][y] << "\n";
  }

  return 0;
}