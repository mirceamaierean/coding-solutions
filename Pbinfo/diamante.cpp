#include <fstream>
using namespace std;

ifstream fin("diamante.in");
ofstream fout("diamante.out");

const int NMAX = 1002;
int n, diag[NMAX][NMAX], k, c;

int getRectangleSum(int x1, int y1, int x2, int y2)
{
  return diag[x2][y2] - diag[x1 - 1][y2] - diag[x2][y1 - 1] + diag[x1 - 1][y1 - 1];
}

int main()
{
  fin >> c;

  fin >> n >> k;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      fin >> diag[n + i - j][i + j - 1];

  for (int i = 1; i <= 2 * n - 1; ++i)
    for (int j = 1; j <= 2 * n - 1; ++j)
      diag[i][j] += diag[i - 1][j] + diag[i][j - 1] - diag[i - 1][j - 1];

  int maxim = 0;

  if (c == 1) // Gaseste suma maxima de pe k diagonale principale consecutive
  {
    for (int i = k; i < 2 * n; ++i)
      maxim = max(maxim, getRectangleSum(i - k + 1, 1, i, 2 * n - 1));
  }

  else if (c == 2) // Gaseste suma maxima de pe k diagonale secundare consecutive
  {
    for (int j = k; j < 2 * n; ++j)
      maxim = max(maxim, getRectangleSum(1, j - k + 1, 2 * n - 1, j));
  }

  else // Gaseste suma maxima de pe k diagonale principale si k diagonale secundare consecutive, in care intersectia se ia o singura data
  {
    for (int i = k; i < 2 * n; ++i)
      for (int j = k; j < 2 * n; ++j)
        maxim = max(maxim, getRectangleSum(1, j - k + 1, 2 * n - 1, j) +
                               getRectangleSum(i - k + 1, 1, i, 2 * n - 1) -
                               getRectangleSum(i - k + 1, j - k + 1, i, j));
  }

  fout << maxim << '\n';

  return 0;
}
