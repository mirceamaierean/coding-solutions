#include <fstream>
#include <queue>
using namespace std;

ifstream cin("insule.in");
ofstream cout("insule.out");

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char a[105][105];
int viz[105][105], car;
int n, m, cnt1, cnt2, cnt3;

queue<pair<int, int>> q;

bool ok(int x, int y)
{
  return x && y && x <= n && y <= m;
}

void Fill(int x, int y)
{
  viz[x][y] = 1;
  for (int k = 0; k < 4; ++k)
  {
    int nx = x + dx[k], ny = y + dy[k];
    if (ok(nx, ny) && viz[nx][ny] == 0)
    {
      if (a[nx][ny] == car)
        Fill(nx, ny);
      else if (car == '1' && a[nx][ny] == '0')
      {
        viz[nx][ny] = 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
}

void Lee()
{
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int k = 0; k < 4; ++k)
    {
      int nx = x + dx[k], ny = y + dy[k];
      if (ok(nx, ny))
      {
        if (viz[nx][ny] == 0)
        {
          viz[nx][ny] = viz[x][y] + 1;
          q.push(make_pair(nx, ny));
        }
        else if (a[nx][ny] == '2')
        {
          cout << viz[x][y];
          return;
        }
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j];

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j] != '0' && viz[i][j] == 0)
      {
        car = a[i][j];
        if (car == '1')
          cnt1++;
        else if (car == '2')
          cnt2++;
        else
          cnt3++;
        Fill(i, j);
      }

  cout << cnt1 << " " << cnt2 << " " << cnt3 << " ";

  Lee();

  return 0;
}