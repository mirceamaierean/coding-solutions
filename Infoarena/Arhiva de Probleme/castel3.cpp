#include <fstream>
#define NMAX 105

using namespace std;

ifstream cin("castel3.in");
ofstream cout("castel3.out");

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

string coor[NMAX][NMAX];

int zone, cnt, a, ump[NMAX][NMAX], n, maxi, vzona, x1, y1, x2, y2;
char c;

void trs(int i, int j)
{
  while (a)
  {
    coor[i][j] += (char)(a % 2 + '0');
    a /= 2;
  }
  while (coor[i][j].size() < 4)
    coor[i][j] += '0';
}

bool ok(int x, int y)
{
  if (x && y && x <= n && y <= n && ump[x][y] == 0)
    return true;
  return false;
}

void Fill_lat(int x, int y)
{
  ump[x][y] = -1;
  for (int i = 0; i < 4; ++i)
  {
    if (coor[x][y][i] == '0')
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ok(nx, ny))
        Fill_lat(nx, ny);
    }
  }
}
void Fill(int x, int y)
{
  cnt++;
  ump[x][y] = zone;
  for (int i = 0; i < 4; ++i)
  {
    if (coor[x][y][i] == '0')
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ok(nx, ny))
        Fill(nx, ny);
    }
  }
}

void solve()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> c >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    {
      cin >> a;
      trs(i, j);
    }
  Fill_lat(1, 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (ump[i][j] == 0)
      {
        cnt = 0;
        zone++;
        Fill(i, j);
        if (cnt > maxi)
        {
          maxi = cnt;
          vzona = zone;
          x1 = i;
          y1 = j;
          x2 = 0;
          y2 = 0;
        }
      }
      else if (ump[i][j] == vzona)
      {
        if (i >= x2 && j >= y2)
        {
          x2 = i;
          y2 = j;
        }
      }
  if (c == '1')
    cout << zone << "\n";
  else if (c == '2')
    cout << maxi << "\n";
  else
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
}

int main()
{
  solve();
  return 0;
}
