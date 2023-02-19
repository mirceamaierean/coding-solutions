#include <fstream>

using namespace std;

ifstream fin("cruce.in");
ofstream fout("cruce.out");

long long cnt, l, c, n, m;

const int NMAX = 102;

char a[NMAX][NMAX];

int main()
{
  fin >> n >> m;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      fin >> a[i][j];

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
      l = 1;
      c = 1;
      while (l < i && i + l <= n && a[i - l][j] == a[i + l][j])
        ++l;
      while (c < j && c + j <= m && a[i][j - c] == a[i][j + c])
        c++;
      --l;
      --c;
      cnt += l * c;
    }
  fout << cnt << "\n";
  return 0;
}
