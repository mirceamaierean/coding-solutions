#include <fstream>
#include <string.h>
#define NMAX 105
using namespace std;
struct marcel
{
  int x, y;
  bool adaug;
  bool are_fantana;
};
marcel s[NMAX * NMAX];
ifstream cin("marceland.in");
ofstream cout("marceland.out");
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, cnt, t, cur;
bool ok;

char a[NMAX][NMAX];
int fil[NMAX][NMAX];

bool valabil(int x, int y)
{
  if (x && y && x <= n && y <= m && a[x][y] != '#' && fil[x][y] == 0)
  {
    if (a[x][y] == '@')
    {
      s[cur].adaug = false;
      s[cur].are_fantana = true;
    }
    else if (a[x][y] == '.' && s[cur].are_fantana == false)
    {
      s[cur].x = x;
      s[cur].y = y;
      s[cur].adaug = true;
    }
    return true;
  }
  return false;
}
void Fill(int x, int y)
{
  fil[x][y] = cur;
  for (int k = 0; k < 4; ++k)
  {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (valabil(nx, ny))
      Fill(nx, ny);
  }
}
void solve()
{
  cin >> t;
  while (t--)
  {
    cnt = 0;
    cur = 1;
    memset(fil, 0, sizeof fil);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (a[i][j] == 'M' && fil[i][j] == 0)
        {
          s[cur].adaug = false;
          s[cur].are_fantana = false;
          s[cur].x = 0;
          s[cur].y = 0;
          Fill(i, j);
          cur++;
        }
    for (int i = 1; i < cur; ++i)
    {
      if (s[i].adaug)
      {
        int x = s[i].x;
        int y = s[i].y;
        a[x][y] = '@';
        cnt++;
      }
      else if (s[i].are_fantana == false)
      {
        cnt = -1;
        break;
      }
    }
    cout << cnt << "\n";
    if (cnt != -1)
    {
      for (int i = 1; i <= n; ++i)
      {
        for (int j = 1; j <= m; ++j)
          cout << a[i][j];
        cout << "\n";
      }
    }
  }
}
int main()
{
  solve();
  return 0;
}
