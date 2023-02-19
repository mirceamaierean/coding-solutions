#include <fstream>

using namespace std;

ifstream cin("zoro.in");
ofstream cout("zoro.out");

int n, m, i, j, z, st, dr, x[1000005], y[1000005], lin[1005], col[1005], k[1000005];

int main()
{
  cin >> n >> m;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= m; j++)
    {

      cin >> z;
      if (i == 1 && j == 1)
        dr = z;
      x[z] = i;
      y[z] = j;
      st = z;
    }
  }
  for (i = dr; i >= st; i--)
  {
    k[i] = max(lin[x[i]], col[y[i]]) + 1;
    lin[x[i]] = k[i];
    col[y[i]] = k[i];
  }
  cout << k[st];
  return 0;
}
