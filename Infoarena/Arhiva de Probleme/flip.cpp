#include <fstream>

using namespace std;

ifstream fin("flip.in");
ofstream fout("flip.out");

int a[20][20], n, m, maxi;

int main()
{
  fin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      fin >> a[i][j];

  for (int mask = 0; mask < (1 << m); ++mask)
  {
    int s_mat = 0;
    for (int i = 1; i <= n; ++i)
    {
      int s = 0;
      for (int j = 1; j <= m; ++j)
        if (mask & (1 << (j - 1)))
          s -= a[i][j];
        else
          s += a[i][j];
      if (s < 0)
        s *= -1;
      s_mat += s;
    }
    if (s_mat > maxi)
      maxi = s_mat;
  }

  fout << maxi << "\n";
  return 0;
}