#include <fstream>
#include <queue>
using namespace std;
ifstream cin("alee.in");
ofstream cout("alee.out");
queue<pair<int, int>> coada;
int di[4] = {0, 0, -1, 1};
int dj[4] = {1, -1, 0, 0};
int a[180][180], n, m, xi, yi, xf, yf, x, y;
void citire()
{
  cin >> n >> m;
  for (int i = 1; i <= m; ++i)
  {
    cin >> x >> y;
    a[x][y] = -1;
  }
  cin >> xi >> yi >> xf >> yf;
}
bool ok(int x, int y)
{
  if (x < 1 || y < 1 || x > n || y > n || a[x][y] == -1)
    return false;
  return true;
}
void Lee()
{
  int i, j, nexti, nextj;
  a[xi][yi] = 1;
  coada.push(make_pair(xi, yi));
  while (!coada.empty())
  {
    i = coada.front().first;
    j = coada.front().second;
    coada.pop();
    for (int k = 0; k < 4; ++k)
    {
      nexti = i + di[k];
      nextj = j + dj[k];
      if (ok(nexti, nextj) && a[nexti][nextj] < 1)
      {
        a[nexti][nextj] = a[i][j] + 1;
        coada.push(make_pair(nexti, nextj));
      }
    }
  }
  cout << a[xf][yf];
}
int main()
{
  citire();
  Lee();
  return 0;
}