#include <fstream>
#include <queue>
#include <vector>
#include <bitset>

class InParser
{
#pragma warning(disable : 4996)
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
  InParser(const char *name)
  {
    sp = 4095;
    buff = new char[4096];
    fin = fopen(name, "r");
  }
  template <class T>
  InParser &operator>>(T &n)
  {
    int sgn = 1;
    char c;
    while (!isdigit(c = read()) && c != '-')
      ;
    if (c == '-')
    {
      n = 0;
      sgn = -1;
    }
    else
      n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    n *= sgn;
    return *this;
  }
  InParser &operator>>(char &n)
  {
    while (!isdigit(n = read()))
      ;
    return *this;
  }
};

InParser fin("pirati.in");
std::ofstream fout("pirati.out");

const int LMAX = 1e3 + 1;

int a[LMAX][LMAX];
std::vector<int> t, level;

int n, m, q, zonesCount;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

char c;

inline bool inside(int x, int y)
{
  return x && y && x <= n && y <= m;
}

int val;

void fill(int x, int y)
{
  a[x][y] = zonesCount;
  for (int i = 0; i < 8; ++i)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (inside(nx, ny))
    {
      if (a[nx][ny] == val)
        fill(nx, ny);
    }
  }
}

void build()
{
  t.resize(zonesCount + 1, -1);
  level.resize(zonesCount + 1, 0);

  t[1] = 0;
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      for (int k = 0; k < 8; ++k)
      {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (inside(nx, ny) && t[a[nx][ny]] == -1)
        {
          t[a[nx][ny]] = a[i][j];
          level[a[nx][ny]] = level[a[i][j]] + 1;
        }
      }
    }
  }
}

int lca(int a, int b)
{
  if (level[a] > level[b])
    std::swap(a, b);

  while (level[a] < level[b])
    b = t[b];

  while (a != b)
  {
    a = t[a];
    b = t[b];
  }

  return a;
}

int main()
{
  fin >> n >> m >> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
      fin >> c;
      if (c == '0')
        a[i][j] = 0;
      else
        a[i][j] = -1;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j] <= 0)
      {
        val = a[i][j];
        ++zonesCount;
        fill(i, j);
      }

  build();

  for (int i = 1; i <= zonesCount; ++i)
    ++level[i];

  int x1, y1, x2, y2;

  while (q--)
  {
    fin >> x1 >> y1 >> x2 >> y2;
    fout << ((level[a[x1][y1]] + level[a[x2][y2]] - (level[lca(a[x1][y1], a[x2][y2])] << 1)) >> 1) << '\n';
  }
  fout.close();
  return 0;
}