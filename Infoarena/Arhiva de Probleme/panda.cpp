#include <fstream>
#include <queue>
#pragma warning(disable : 4996)
using namespace std;

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
    buff = new char[4096];
    sp = 4095;
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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

const int NMAX = 502;

queue<pair<int, int>> q;

InParser fin("panda.in");
ofstream fout("panda.out");

int p, mini;

int a[NMAX][NMAX], lee_dist[NMAX][NMAX];

int n, m, t, l, c, k, s;

char fr[NMAX][NMAX];

int x, y, cnt;

inline bool ok(int x, int y)
{
  return x && y && x <= n && y <= m && a[x][y] == 1 && !(x == l && y == c) && lee_dist[x][y] == 0;
}

void Lee()
{
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (fr[x][y] == 1)
    {
      if (lee_dist[x][y] < mini)
      {
        cnt = 1;
        mini = lee_dist[x][y];
      }
      else if (lee_dist[x][y] == mini)
        cnt++;
    }
    for (int i = 0; i < 4; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ok(nx, ny))
      {
        lee_dist[nx][ny] = lee_dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
}

inline bool compare(int a, int b, int s)
{
  while (s)
  {
    if ((a & 1) == (b & 1))
      return 0;
    --s;
    a >>= 1;
    b >>= 1;
  }
  return 1;
}

int main()
{

  mini = NMAX * NMAX;

  fin >> p >> n >> m >> t >> l >> c >> k >> s;

  while (t--)
  {
    fin >> x >> y;
    fr[x][y] = 1;
  }

  cnt = -1;

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      fin >> a[i][j];
      a[i][j] = compare(a[i][j], k, s);
      cnt += a[i][j];
    }
  }
  if (p == 1)
    fout << cnt << "\n";
  else
  {
    cnt = 0;
    q.push({l, c});
    Lee();
    fout << mini << " " << cnt << "\n";
  }
  return 0;
}
