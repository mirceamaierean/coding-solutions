#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;

ifstream fin("cartite.in");
ofstream fout("cartite.out");

const int NMAX = 201;
typedef pair<int, int> per;

int p, m, n, x0, y0, a[NMAX][NMAX], x, y, k, g, r, x1, y1, safe_x, safe_y, val;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int diagx[] = {1, -1, 1, -1};
int diagy[] = {1, -1, -1, 1};

vector<pair<per, int>> G[NMAX][NMAX];

inline bool inside(int x, int y)
{
  return x && y && x <= m && y <= n;
}

bitset<NMAX> used;

void Lee()
{
  queue<per> q;

  q.push({x0, y0});

  if (a[x0][y0] == -2)
  {
    fout << x0 << " " << y0 << " " << 0 << '\n';
    return;
  }
  a[x0][y0] = 1;

  while (!q.empty())
  {
    per p = q.front();

    q.pop();

    for (int i = 0; i < 4; ++i)
    {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (inside(nx, ny))
      {
        if (a[nx][ny] == -2)
        {
          safe_x = nx;
          safe_y = ny;
          val = a[p.first][p.second];
          return;
        }
        if (a[nx][ny] == 0)
        {
          a[nx][ny] = a[p.first][p.second] + 1;
          q.push({nx, ny});
        }
      }
    }
  }
}

vector<per> cycle;

void solve()
{
  stack<per> st;
  st.push({x, y});

  while (!st.empty())
  {
    per node = st.top();

    while (!G[node.first][node.second].empty() && used[G[node.first][node.second].back().second])
      G[node.first][node.second].pop_back();

    if (!G[node.first][node.second].empty())
    {
      per new_node = G[node.first][node.second].back().first;
      st.push(new_node);
      used[G[node.first][node.second].back().second] = 1;
    }

    else
    {
      st.pop();
      if (!st.empty())
        cycle.push_back(st.top());
    }
  }
}

int main()
{
  fin >> p >> m >> n >> x0 >> y0 >> k;

  for (int i = 1; i <= k; ++i)
  {
    fin >> x >> y >> r;
    a[x][y] = -1;
    if (r == 2)
    {
      for (int j = 0; j < 4; ++j)
      {
        int nx = x + diagx[j], ny = y + diagy[j];
        if (inside(nx, ny))
          a[nx][ny] = -1;
      }
    }
    for (; r > 0; r--)
    {
      for (int j = 0; j < 4; ++j)
      {
        int nx = x + dx[j] * r, ny = y + dy[j] * r;
        if (inside(nx, ny))
          a[nx][ny] = -1;
      }
    }
  }

  fin >> g;

  for (int i = 1; i <= g; ++i)
  {
    fin >> x >> y >> x1 >> y1;
    if (a[x][y] == 0)
      a[x][y] = -2;

    if (a[x1][y1] == 0)
      a[x1][y1] = -2;

    G[x][y].push_back({{x1, y1}, i});
    G[x1][y1].push_back({{x, y}, i});
  }

  Lee();

  if (p == 1)
    fout << safe_x << " " << safe_y << " " << val << '\n';
  else
  {
    solve();
    int index = 0;
    for (int i = 0; i < cycle.size(); ++i)
      if (cycle[i].first == safe_x && cycle[i].second == safe_y)
      {
        index = i;
        break;
      }
    for (int i = index; i < cycle.size(); ++i)
      fout << cycle[i].first << " " << cycle[i].second << '\n';

    for (int i = 0; i <= index; ++i)
      fout << cycle[i].first << " " << cycle[i].second << '\n';
  }
  return 0;
}
