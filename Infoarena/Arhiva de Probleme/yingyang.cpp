#include <fstream>

using namespace std;

ifstream cin("yinyang.in");
ofstream cout("yinyang.out");
int a[101][101], n, m, cnt;
void linie(int l)
{
  ++cnt;
  for (int i = 1; i <= m; ++i)
    swap(a[l][i], a[l + 1][i]);
}
void coloana(int c)
{
  ++cnt;
  for (int i = 1; i <= n; ++i)
    swap(a[i][c], a[i][c + 1]);
}
int main()
{
  bool ok = 1;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j];
  while (ok)
  {
    ok = 0;
    for (int i = 1; i < n; ++i)
      for (int j = 1; j <= m; ++j)
        if (a[i][j] > a[i + 1][j])
        {
          linie(i);
          ok = 1;
          break;
        }
        else if (a[i][j] != a[i + 1][j])
          break;
    for (int j = 1; j < m; ++j)
      for (int i = 1; i <= n; ++i)
        if (a[i][j] > a[i][j + 1])
        {
          coloana(j);
          ok = 1;
          break;
        }
        else if (a[i][j] != a[i][j + 1])
          break;
  }
  ok = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j <= m; ++j)
      if (a[i][j] < a[i][j - 1])
        ok = 0;
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (a[i][j] < a[i - 1][j])
        ok = 0;
  if (ok)
    cout << cnt;
  else
    cout << -1;
  cout << "\n";
  return 0;
}
