#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("ferma3.in");
ofstream fout("ferma3.out");

const int NMAX = 405;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int marcat[NMAX][NMAX];
char a[NMAX][NMAX];
int s[NMAX * NMAX];
int n, m, ind, cnt;
char cer;

inline bool ok(int x, int y)
{
  return x && y && x <= n && y <= m && marcat[x][y] == 0;
}

void Fill(int x, int y)
{
  cnt++;
  marcat[x][y] = ind;
  for (int i = 0; i < 4; ++i)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (ok(nx, ny) && a[nx][ny] == a[x][y])
      Fill(nx, ny);
  }
}

int main()
{
  int maxi = -1000;
  fin >> cer;
  fin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      fin >> a[i][j];
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      if (marcat[i][j] == 0)
      {
        ++ind;
        cnt = 0;
        Fill(i, j);
        s[ind] = cnt;
        if (cnt > maxi)
          maxi = cnt;
      }
    }
  }
  if (cer == '1')
    fout << maxi << "\n";
  else
  {
    maxi = -1;
    int ax = 0, ay = 0;
    char car = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
      {
        int sol = 0, v1 = marcat[i - 1][j], v2 = marcat[i][j - 1], v3 = marcat[i + 1][j], v4 = marcat[i][j + 1];
        if (a[i - 1][j] == a[i][j - 1] && a[i - 1][j] == a[i + 1][j] && a[i - 1][j] == a[i][j + 1]) // 1 2 3 4
        {
          sol = s[v1] + (a[i][j] != a[i - 1][j]);
          if (v1 != v2)
            sol += s[v2];
          if (v1 != v3 && v2 != v3)
            sol += s[v3];
          if (v1 != v4 && v2 != v4 && v3 != v4)
            sol += s[v4];
          if (sol >= maxi)
          {
            maxi = sol;
            ax = i;
            ay = j;
            car = a[i - 1][j];
          }
        }
        else if (a[i - 1][j] == a[i][j - 1] && a[i - 1][j] == a[i + 1][j]) // 1 2 3
        {
          sol = s[v1] + (a[i][j] != a[i - 1][j]);
          if (v1 != v2)
            sol += s[v2];
          if (v1 != v3 && v2 != v3)
            sol += s[v3];
          if (sol >= maxi)
          {
            maxi = sol;
            ax = i;
            ay = j;
            car = a[i - 1][j];
          }
        }
        else if (a[i - 1][j] == a[i + 1][j] && a[i - 1][j] == a[i][j + 1]) // 1 3 4
        {
          sol = s[v1] + (a[i][j] != a[i - 1][j]);
          if (v1 != v3)
            sol += s[v3];
          if (v1 != v4 && v3 != v4)
            sol += s[v4];
          if (sol >= maxi)
          {
            maxi = sol;
            ax = i;
            ay = j;
            car = a[i - 1][j];
          }
        }
        else if (a[i - 1][j] == a[i][j - 1] && a[i - 1][j] == a[i][j + 1]) // 1 2 4
        {
          sol = s[v1] + (a[i][j] != a[i - 1][j]);
          if (v1 != v2)
            sol += s[v2];
          if (v1 != v4 && v2 != v4)
            sol += s[v4];
          if (sol >= maxi)
          {
            maxi = sol;
            ax = i;
            ay = j;
            car = a[i - 1][j];
          }
        }
        else if (a[i][j - 1] == a[i + 1][j] && a[i][j - 1] == a[i][j + 1]) // 2 3 4
        {
          sol = s[v2] + (a[i][j] != a[i][j - 1]);
          if (v2 != v3)
            sol += s[v3];
          if (v2 != v4 && v3 != v4)
            sol += s[v4];
          if (sol >= maxi)
          {
            maxi = sol;
            ax = i;
            ay = j;
            car = a[i - 1][j];
          }
        }
        else if (a[i - 1][j] == a[i][j - 1]) // 1 2
        {
          sol = s[v1] + (a[i][j] != a[i - 1][j]);
          if (v1 != v2)
            sol += s[v2];
          if (sol >= maxi)
          {
            maxi = sol;
            ax = i;
            ay = j;
            car = a[i - 1][j];
          }
        }
        else if (a[i - 1][j] == a[i + 1][j]) // 1 3
        {
          sol = s[v1] + (a[i][j] != a[i - 1][j]);
          if (v1 != v3)
            sol += s[v3];
          if (sol >= maxi && i > 1)
          {
            maxi = sol;
            ax = i;
            ay = j;
            car = a[i - 1][j];
          }
        }
        else if (a[i - 1][j] == a[i][j + 1]) // 1 4
        {
          sol = s[v1] + (a[i][j] != a[i - 1][j]);
          if (v1 != v4)
            sol += s[v4];
          if (sol >= maxi)
          {
            maxi = sol;
            ax = i;
            ay = j;
            car = a[i - 1][j];
          }
        }
        else if (a[i][j - 1] == a[i + 1][j]) // 2 3
        {
          sol = s[v2] + (a[i][j] != a[i][j - 1]);
          if (v2 != v3)
            sol += s[v3];
          if (sol >= maxi)
          {
            maxi = sol;
            ax = i;
            ay = j;
            car = a[i][j - 1];
          }
        }
        else if (a[i][j - 1] == a[i][j + 1]) // 2 4
        {
          sol = s[v2] + (a[i][j] != a[i][j - 1]);
          if (v2 != v4)
            sol += s[v4];
          if (sol >= maxi)
          {
            maxi = sol;
            ax = i;
            ay = j;
            car = a[i][j - 1];
          }
        }
        else if (a[i + 1][j] == a[i][j + 1]) // 3 4
        {
          sol = s[v3] + (a[i][j] != a[i + 1][j]);
          if (v3 != v4)
            sol += s[v4];
          if (sol >= maxi)
          {
            maxi = sol;
            ax = i;
            ay = j;
            car = a[i + 1][j];
          }
        }
        else if (s[v1] + (a[i - 1][j] != a[i][j]) >= maxi) // 1
        {
          maxi = sol;
          ax = i;
          ay = j;
          car = a[i - 1][j];
        }
        else if (s[v2] + (a[i][j - 1] != a[i][j]) >= maxi) // 2
        {
          maxi = sol;
          ax = i;
          ay = j;
          car = a[i][j - 1];
        }
        else if (s[v3] + (a[i + 1][j] != a[i][j]) >= maxi) // 3
        {
          maxi = sol;
          ax = i;
          ay = j;
          car = a[i + 1][j];
        }
        else if (s[v4] + (a[i][j + 1] != a[i][j]) >= maxi) // 4
        {
          maxi = sol;
          ax = i;
          ay = j;
          car = a[i][j + 1];
        }
      }
    fout << ax << " " << ay << "\n"
         << car << "\n";
  }
  return 0;
}
