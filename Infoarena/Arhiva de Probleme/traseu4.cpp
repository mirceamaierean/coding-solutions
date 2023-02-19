#include <fstream>
using namespace std;

const int NMAX = 503;

ifstream fin("traseu4.in");
ofstream fout("traseu4.out");

int mat[NMAX][NMAX];
int n, m, maxi;

int main()
{

  fin >> n >> m;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
      fin >> mat[i][j];
      int x = i;
      while (x > 1 && mat[x - 1][j] < mat[i][j])
        --x;

      int y = j;
      while (y > 1 && mat[x][y - 1] < mat[i][j])
        --y;

      maxi = max(maxi, i + j - x - y);

      if (i > 1)
        mat[i][j] = min(mat[i][j], mat[i - 1][j]);
      if (j > 1)
        mat[i][j] = min(mat[i][j], mat[i][j - 1]);
    }

  maxi += 1;

  if (maxi == 1)
    maxi = 0;

  fout << maxi << "\n";

  return 0;
}
