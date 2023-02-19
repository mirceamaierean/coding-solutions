#include <fstream>
#include <string.h>
using namespace std;

ifstream fin("rfinv.in");
ofstream fout("rfinv.out");

int n, t, a[55][55], v[55][55], m, x, y;
bool ok;

void read()
{
  memset(a, 0, sizeof a);
  memset(v, 0, sizeof v);
  fin >> n >> m;
  for (int i = 1; i <= m; ++i)
  {
    fin >> x >> y;
    v[x][y] = 1;
    v[y][x] = 1;
  }

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
    {
      fin >> a[i][j];
      if (i != j && a[i][j] == 0)
        a[i][j] = (1 << 20);
      if (v[i][j])
        v[i][j] = a[i][j];
      else if (i != j)
        v[i][j] = (1 << 20);
    }
}

bool solve()
{
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (v[i][k] && v[k][j] && v[i][j] > v[i][k] + v[k][j] && i != j)
          v[i][j] = v[i][k] + v[k][j];

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (a[i][j] != v[i][j])
        return false;

  return true;
}

int main()
{
  fin >> t;
  while (t--)
  {
    read();
    solve();
    if (solve())
      fout << "DA\n";
    else
      fout << "NU\n";
  }
  fout.close();
  return 0;
}