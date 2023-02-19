#include <fstream>
#include <vector>
#include <bitset>
#include <vector>

std::ifstream fin("immortal.in");
std::ofstream fout("immortal.out");

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

typedef std::pair<int, int> p;
typedef std::pair<p, p> pp;

std::vector<pp> solution;

int x, y, n, m, im;

inline bool inside(int nx, int ny)
{
  return nx > 0 && ny > 0 && nx <= n && ny <= m;
}

bool ok;

std::bitset<22> imm[22];

bool neighbour(p x)
{
  for (int i = 0; i < 4; ++i)
  {
    int vx = x.first + dx[i];
    int vy = x.second + dy[i];

    int nx = vx + dx[i];
    int ny = vy + dy[i];

    if (imm[vx][vy] == 1)
      if (inside(nx, ny) && imm[nx][ny] == 0)
        return 1;
  }

  return 0;
}

void solve(int cnt)
{
  std::vector<p> positions;
  std::vector<p> v;

  for (int i = n; i >= 1; --i)
    for (int j = m; j >= 1; --j)
    {
      if (imm[i][j])
      {
        positions.push_back({i, j});
        if (neighbour({i, j}))
          v.push_back({i, j});
      }
    }

  for (auto x : v)
  {
    for (int d = 0; d < 4; ++d)
    {
      int vx = x.first + dx[d];
      int vy = x.second + dy[d];

      int nx = vx + dx[d];
      int ny = vy + dy[d];

      if (imm[vx][vy] == 1 && inside(nx, ny) && imm[nx][ny] == 0)
      {
        if (cnt == 2)
        {
          ok = true;

          for (auto s : solution)
            fout << s.first.first << " " << s.first.second << " " << s.second.first << " " << s.second.second << "\n";

          fout << x.first << " " << x.second << ' ' << nx << " " << ny << "\n";

          return;
        }

        imm[vx][vy] = 0;
        imm[x.first][x.second] = 0;
        imm[nx][ny] = 1;

        if (v.size() - 4 * (1 - neighbour({nx, ny})) > 0)
        {
          solution.push_back({x, {nx, ny}});

          solve(cnt - 1);

          if (ok)
            return;

          solution.pop_back();
        }

        imm[x.first][x.second] = 1;
        imm[nx][ny] = 0;
        imm[vx][vy] = 1;
      }
    }
  }
}

int main()
{
  fin >> n >> m >> im;

  for (int i = 1; i <= im; ++i)
  {
    fin >> x >> y;
    imm[x][y] = 1;
  }

  solve(im);

  fout.close();
  return 0;
}