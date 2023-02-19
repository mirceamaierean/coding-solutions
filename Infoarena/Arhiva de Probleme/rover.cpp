#include <fstream>
#include <deque>
#include <limits.h>
#include <string.h>
#define NMAX 503

using namespace std;

ifstream cin("rover.in");
ofstream cout("rover.out");

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

deque<pair<int, int>> q;

int a[NMAX][NMAX], maxi, cnt, n, g, s, d;
bool viz[NMAX][NMAX];
int lee[NMAX][NMAX];
char caz;

bool ok(int x, int y)
{
  if (x && y && x <= n && y <= n && viz[x][y] == 0)
    return true;
  return false;
}

void Zone()
{
  q.push_back(make_pair(1, 1));
  while (q.size())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop_front();
    viz[x][y] = 1;
    for (int i = 0; i < 4; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ok(nx, ny))
      {
        lee[nx][ny] = INT_MAX;
        for (int k = 0; k < 4; ++k)
        {
          int x1 = nx + dx[k];
          int y1 = ny + dy[k];
          if (viz[x1][y1] == 1)
            lee[nx][ny] = min(lee[nx][ny], lee[x1][y1]);
        }
        if (nx == n && ny == n)
        {
          q.clear();
          break;
        }
        else if (a[nx][ny] < g)
        {
          lee[nx][ny]++;
          q.push_back(make_pair(nx, ny));
        }
        else
          q.push_front(make_pair(nx, ny));
      }
    }
  }
}

bool Lee()
{
  memset(viz, 0, sizeof viz);
  q.clear();
  q.push_back(make_pair(1, 1));
  while (q.size())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop_front();
    viz[x][y] = 1;
    for (int i = 0; i < 4; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ok(nx, ny))
      {
        if (nx == n && ny == n)
          return 1;
        if (a[nx][ny] >= g)
          q.push_front(make_pair(nx, ny));
      }
    }
  }
  return 0;
}

void read()
{
  cin >> caz >> n;
  if (caz == '1')
  {
    cin >> g;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        cin >> a[i][j];
    Zone();
    cout << lee[n][n] << "\n";
  }
  else
  {
    s = INT_MAX;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
      {
        cin >> a[i][j];
        if (a[i][j] < s)
          s = a[i][j];
        if (a[i][j] > d)
          d = a[i][j];
      }
    while (s < d)
    {
      g = (s + d) / 2;
      if (Lee())
      {
        s = g + 1;
        if (g > maxi)
          maxi = g;
      }
      else
        d = g - 1;
      q.clear();
    }
    if (g != d)
    {
      g = d;
      if (Lee())
        maxi = g;
    }
    cout << maxi << "\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  read();
  return 0;
}
