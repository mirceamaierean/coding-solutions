#include <fstream>
#include <queue>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

const int oo = 0x3f3f3f3f;
const int NMAX = 2003;
const int KMAX = 17;

class InParser
{
private:
  FILE *fin;
  char *buff;
  int sp;
  char read()
  {
    ++sp;
    if (sp == 4096)
    {
      sp = 0;
      fread(buff, 1, 4096, fin);
    }
    return buff[sp];
  }

public:
  InParser(const char *nume)
  {
    buff = new char[4096];
    fin = fopen(nume, "r");
    sp = 4095;
  }
  InParser &operator>>(int &n)
  {
    char c;
    while (!isdigit(c = read()))
      ;
    n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    return *this;
  }
};

InParser fin("ubuntzei.in");
ofstream fout("ubuntzei.out");

int n, m, d[NMAX], k;
vector<pair<int, int>> g[NMAX];
priority_queue<pair<int, int>> q;

void Dijkstra(int start)
{
  memset(d, oo, sizeof d);
  d[start] = 0;
  q.push({0, start});
  while (!q.empty())
  {
    int cost = -q.top().first, x = q.top().second;
    q.pop();
    for (size_t i = 0; i < g[x].size(); ++i)
    {
      if (g[x][i].second + cost < d[g[x][i].first])
      {
        d[g[x][i].first] = g[x][i].second + cost;
        q.push({-d[g[x][i].first], g[x][i].first});
      }
    }
  }
}

int x, y, cost, len[KMAX][KMAX], dp[(1 << KMAX)][KMAX];

int main()
{
  fin >> n >> m >> k;

  vector<int> s;

  s.push_back(0);

  for (int i = 1; i <= k; ++i)
  {
    fin >> x;
    --x;
    s.push_back(x);
  }
  s.push_back(n - 1);
  for (int i = 1; i <= m; ++i)
  {
    fin >> x >> y >> cost;
    --x;
    --y;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }
  for (int i = 0; i < s.size(); ++i)
  {
    Dijkstra(s[i]);
    for (int j = 0; j < s.size(); ++j)
      len[i][j] = d[s[j]];
  }

  memset(dp, oo, sizeof dp);

  dp[1][0] = 0;

  int c = (1 << s.size());

  for (int mask = 1; mask < c; ++mask)
  {
    for (int i = 0; i < s.size(); ++i)
      if (mask & (1 << i))
        for (int j = 0; j < s.size(); ++j)
          if (mask & (1 << j))
            dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + len[j][i]);
  }

  fout << dp[c - 1][s.size() - 1] << "\n";

  return 0;
}