#include <fstream>
#include <deque>
#include <string.h>
#define push push_back
#define pop pop_front
#define NMAX 105

using namespace std;

ifstream cin("pietre2.in");
ofstream cout("pietre2.out");

deque<pair<int, int>> q;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int lee[NMAX][NMAX], a[NMAX][NMAX], ax, ay;
char viz[NMAX][NMAX];
bool k;
int n, maxi;

bool ok(int x, int y)
{
  return x && y && x <= n && y <= n && viz[x][y] == 0;
}

void Lee()
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
      if (ok(nx, ny) && a[nx][ny] == a[x][y] + 1)
      {
        lee[nx][ny] = lee[x][y] + 1;
        if (lee[nx][ny] > maxi)
        {
          k = true;
          maxi = lee[nx][ny];
        }
        q.push(make_pair(nx, ny));
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> a[i][j];
  for (int i = 1; i <= n; ++i)
  {
    k = false;
    q.push(make_pair(1, i));
    lee[1][i] = 0;
    Lee();
    if (k)
    {
      ax = 1;
      ay = i;
    }
  }
  for (int i = 2; i <= n; ++i)
  {
    k = false;
    q.push(make_pair(i, 1));
    lee[i][1] = 0;
    Lee();
    if (k)
    {
      ax = i;
      ay = 1;
    }
  }
  for (int i = 2; i <= n; ++i)
  {
    k = false;
    q.push(make_pair(n, i));
    lee[n][i] = 0;
    Lee();
    if (k)
    {
      ax = n;
      ay = i;
    }
  }
  for (int i = 2; i < n; ++i)
  {
    k = false;
    q.push(make_pair(i, n));
    lee[i][n] = 0;
    Lee();
    if (k)
    {
      ax = i;
      ay = n;
    }
  }
  cout << maxi << "\n"
       << ax << " " << ay << "\n";
  return 0;
}