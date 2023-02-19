#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <queue>
#pragma warning(disable : 4996)

using namespace std;

typedef pair<int, int> p;

const int NMAX = 1e5 + 2;
const int oo = -0x3f3f3f3f;

class parsare
{
private:
  FILE *fin;
  int sp;
  char *buff;
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
  parsare(const char *nume)
  {
    sp = 4095;
    fin = fopen(nume, "r");
    buff = new char[4096];
  }
  parsare &operator>>(int &n)
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

parsare fin("rusuoaica.in");
ofstream fout("rusuoaica.out");

vector<p> g[NMAX];

bitset<NMAX> used;

int n, m, x, y, d, c[NMAX];

struct cmp
{
  bool operator()(const p &x, const p &y) const
  {
    return x.second > y.second;
  }
};

int apm(int start)
{
  priority_queue<p, vector<p>, cmp> q;

  q.push({start, 0});

  used[0] = 1;
  c[start] = 0;

  int total = 0;

  while (1)
  {
    int x = 0;
    while (used[x] && !q.empty())
    {
      x = q.top().first;
      q.pop();
    }
    if (used[x] == 1)
      return total;
    total += c[x];
    used[x] = 1;
    for (size_t i = 0; i < g[x].size(); ++i)
    {
      if (g[x][i].second < c[g[x][i].first] && used[g[x][i].first] == 0)
      {
        c[g[x][i].first] = g[x][i].second;
        q.push(g[x][i]);
      }
    }
  }
}

int val, total, a, cost_total, prf;

int main()
{

  val = oo;
  fin >> n >> m >> a;
  for (int i = 1; i <= m; ++i)
  {
    fin >> x >> y >> d;
    if (d <= a)
    {
      g[x].push_back({y, d});
      g[y].push_back({x, d});
    }
    cost_total += d;
  }
  fill(c + 1, c + n + 1, -oo);
  int cnt = -1;
  for (int i = 1; i <= n; ++i)
  {
    if (used[i] == 0)
    {
      total += apm(i);
      ++cnt;
    }
  }
  cost_total -= 2 * total;
  cost_total -= a * cnt;
  fout << -cost_total << "\n";
  return 0;
}
