#include <fstream>
#include <queue>
#include <algorithm>
#include <cmath>

std::ifstream fin("labirint2.in");
std::ofstream fout("labirint2.out");

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, index;

inline bool inside(int x, int y)
{
  return x && y && x <= n && y <= m;
}

const int NMAX = 1e3 + 2;

int dist[2][NMAX][NMAX];
char a[NMAX][NMAX];

void Lee(int x, int y)
{
  std::queue<std::pair<int, int>> q;

  q.push({x, y});

  while (!q.empty())
  {
    int c1 = q.front().first, c2 = q.front().second;

    q.pop();

    for (int i = 0; i < 4; ++i)
    {
      int nx = c1 + dx[i];
      int ny = c2 + dy[i];

      if (inside(nx, ny) && dist[index][nx][ny] == 0)
      {
        dist[index][nx][ny] = dist[index][c1][c2] + 1;

        if (a[nx][ny] == 1)
          dist[index][nx][ny] = -dist[index][nx][ny];

        else
          q.push({nx, ny});
      }
    }
  }
}

int main()
{
  fin >> n >> m;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    {
      fin >> a[i][j];
      a[i][j] -= '0';
    }

  dist[0][1][1] = 1;

  dist[1][n][m] = 1;

  Lee(1, 1);

  index = 1;

  Lee(n, m);

  for (int i = 1; i <= n; ++i, fout << "\n")
    for (int j = 1; j <= m; ++j)
      if (a[i][j] == 1)
      {
        if (dist[0][i][j] && dist[1][i][j] && std::abs(dist[0][i][j] + dist[1][i][j]) - 1 < dist[1][1][1])
          fout << 1;
        else
          fout << 0;
      }
      else
        fout << 0;

  fout.close();
  return 0;
}
