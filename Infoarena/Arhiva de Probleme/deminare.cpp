#include <fstream>
#include <cmath>
using namespace std;
ifstream cin("deminare.in");
ofstream cout("deminare.out");
int p[501][501];
long long s[501][501];
int main()
{
  char u;
  int x, y, m, l, c;
  cin >> u;
  cin >> l >> c >> m;
  for (int i = 1; i <= m; ++i)
  {
    cin >> x >> y;
    p[x][y] = 1;
  }
  for (int i = 1; i <= l; i++)
    for (int j = 1; j <= c; j++)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + p[i][j];
  int max = 0;
  if (u == '1')
  {
    for (int i = 1; i <= l; ++i)
      if (s[i][c] - s[i - 1][c] > max)
        max = s[i][c] - s[i - 1][c];
    for (int i = 1; i <= l; ++i)
      if (s[i][c] - s[i - 1][c] == max)
        cout << i << " ";
  }
  else
  {
    int min = m, a, b;
    for (int e = 1; e <= m; ++e)
      if (m % e == 0 && e <= c && e <= l)
      {
        a = e;
        b = m / e;
        if (a > l || b > c)
          swap(a, b);
        int suma = 0;
        for (int i = 1; i <= l - a + 1; ++i)
          for (int j = 1; j <= c - b + 1; ++j)
          {
            suma = s[i + a - 1][j + b - 1] - s[i - 1][j + b - 1] - s[i + a - 1][j - 1] + s[i - 1][j - 1];
            if (m - suma < min)
              min = m - suma;
          }
      }
    if (min == m)
      cout << -1;
    else
      cout << min;
  }
  return 0;
}
