#include <fstream>
#include <queue>
#pragma warning(disable : 4996)
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

typedef pair<int, int> p;

queue<p> q;

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

InParser fin("tsunami.in");
ofstream fout("tsunami.out");

const int NMAX = 1003;

int a[NMAX][NMAX], n, m, h, cnt;
char viz[NMAX][NMAX];

inline bool ok(int x, int y)
{
  return x && y && x <= n && y <= m && a[x][y] && viz[x][y] == 0 && a[x][y] < h;
}

void Lee()
{
  while (!q.empty())
  {
    int x = q.front().first, y = q.front().second;
    cnt++;
    q.pop();
    for (int i = 0; i < 4; ++i)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ok(nx, ny))
      {
        q.push({nx, ny});
        viz[nx][ny] = 1;
      }
    }
  }
  fout << cnt << "\n";
}

int main()
{
  fin >> n >> m >> h;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      fin >> a[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
      if (a[i][j] == 0)
      {
        for (int k = 0; k < 4; ++k)
        {
          int x = i + dx[k];
          int y = j + dy[k];
          if (ok(x, y))
          {
            q.push({x, y});
            viz[x][y] = 1;
          }
        }
      }
    }
  Lee();
  return 0;
}