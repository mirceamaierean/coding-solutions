#include <fstream>
#include <string.h>
#include <limits.h>
#include <queue>
#include <algorithm>
#define NMAX 65
using namespace std;

ifstream fin("miting.in");
ofstream fout("miting.out");

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

queue<int> q;
deque<pair<int, int>> poz;

int n, m, l1, l2, c1, c2, c, p;
string a;
char mat[NMAX][NMAX];
int d[NMAX][NMAX][NMAX * NMAX], start[NMAX][NMAX];

inline bool ok(int x, int y)
{
  return x >= 0 && y >= 0 && x < n && y < m && mat[x][y] != '#';
}

vector<int> pos('Z' + 1);

inline bool cmp(pair<int, int> p1, pair<int, int> p2)
{
  return pos[mat[p1.first][p1.second]] < pos[mat[p2.first][p2.second]];
}

void Lee(int l, int c)
{
  while (!q.empty())
  {
    int x = q.front();
    int i = poz[x].first, j = poz[x].second;
    q.pop();
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = i + dx[dir], ny = j + dy[dir];
      int y = start[nx][ny];
      if (ok(nx, ny) && d[l][c][y] > d[l][c][x] + 1)
      {
        d[l][c][y] = d[l][c][x] + 1;
        q.push(y);
      }
    }
  }
}

int main()
{
  c1 = NMAX;
  l1 = NMAX;

  fin >> c;
  fin >> n >> m;
  fin >> a;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    {
      fin >> mat[i][j];
      if (isalpha(mat[i][j]))
      {
        if (j < c1)
          c1 = j;
        if (j > c2)
          c2 = j;
        if (i < l1)
          l1 = i;
        if (i > l2)
          l2 = i;
        poz.push_front(make_pair(i, j));
      }
      else if (mat[i][j] != '#')
        poz.push_back(make_pair(i, j));
    }
  if (c == 1)
  {
    fout << (l2 - l1 + 1) * (c2 - c1 + 1) << "\n";
    return 0;
  }
  int mini = INT_MAX, nc = a.size();

  for (int i = 0; i < nc; ++i)
    pos[a[i]] = i;

  sort(poz.begin(), poz.begin() + nc, cmp);

  int s = poz.size();

  for (int k = 0; k < s; ++k)
  {
    int i = poz[k].first, j = poz[k].second;
    start[i][j] = k;
  }

  for (int i = 0; i < nc; ++i)
  {
    for (int x = 0; x < s; ++x)
      for (int j = 0; j < nc; ++j)
        d[i][j][x] = INT_MAX;

    d[i][i][i] = 0;
    q.push(i);
    Lee(i, i);
  }

  for (int l = 2; l <= nc; ++l)
    for (int i = 0; i < nc - l + 1; ++i)
    {
      int j = i + l - 1, val;
      for (int x = 0; x < s; ++x)
      {
        val = d[i][j][x];
        for (int k = i; k < j; ++k)
          val = min(val, d[i][k][x] + d[k + 1][j][x]);
        if (val < d[i][j][x])
        {
          d[i][j][x] = val;
          q.push(x);
        }
      }
      if (l < nc)
        Lee(i, j);
    }

  for (int i = 0; i < s; ++i)
    if (d[0][nc - 1][i] > 0)
      mini = min(mini, d[0][nc - 1][i]);

  if (mini == INT_MAX)
    mini = -1;
  fout << mini << "\n";
  return 0;
}
