#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class InParser
{
#pragma warning(disable : 4996)
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
    sp = 4095;
    buff = new char[4096];
    fin = fopen(nume, "r");
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

InParser fin("viteza.in");
ofstream fout("viteza.out");

const int NMAX = 1e5 + 5;
const int KMAX = 20;

bitset<NMAX> used;

vector<int> g[NMAX];
vector<pair<int, int>> q[NMAX];
vector<pair<int, int>> scz[NMAX];

int n, m, a[NMAX - 2], s[NMAX];
int aib[2 * NMAX];

inline int ub(int i)
{
  return i & -i;
}

void update_aib(int p, int val)
{
  for (int i = p; i < NMAX; i += ub(i))
    aib[i] += val;
}

int query_aib(int p)
{
  int s(0);
  for (int i = p; i; i -= ub(i))
    s += aib[i];
  return s;
}

int x, y, c, k;
int rmq[KMAX][2 * NMAX], lg[2 * NMAX], fst[NMAX], deep[NMAX], euler[2 * NMAX], euler_lvl[2 * NMAX];

void DFS(int node)
{
  euler[++k] = node;
  euler_lvl[k] = deep[node];
  fst[node] = k;
  used[node] = 1;
  for (auto i : g[node])
  {
    if (used[i] == 0)
    {
      deep[i] = deep[node] + 1;
      DFS(i);
      euler[++k] = node;
      euler_lvl[k] = deep[node];
    }
  }
}

void RMQ()
{
  rmq[0][1] = 1;
  for (int i = 2; i <= k; ++i)
  {
    lg[i] = lg[i >> 1] + 1;
    rmq[0][i] = i;
  }
  for (int i = 1; (1 << i) <= k; ++i)
    for (int j = 1; j + (1 << i) - 1 <= k; ++j)
    {
      int ind1 = rmq[i - 1][j], ind2 = rmq[i - 1][j + (1 << (i - 1))];
      if (euler_lvl[ind1] > euler_lvl[ind2])
        rmq[i][j] = ind2;
      else
        rmq[i][j] = ind1;
    }
}

int lca(int x, int y)
{
  x = fst[x];
  y = fst[y];
  if (x > y)
    swap(x, y);
  int t = lg[y - x + 1];
  int ind1 = rmq[t][x], ind2 = rmq[t][y - (1 << t) + 1];
  if (euler_lvl[ind1] < euler_lvl[ind2])
    return euler[ind1];
  return euler[ind2];
}

void solve(int node)
{
  used[node] = 1;
  update_aib(a[node], 1);

  for (auto i : q[node])
    s[i.first] += query_aib(i.second);

  for (auto i : g[node])
  {
    if (used[i] == 0)
      solve(i);
  }
  for (auto i : scz[node])
  {
    s[i.first] -= 2 * query_aib(i.second);
    if (a[node] <= i.second)
      s[i.first]++;
  }
  update_aib(a[node], -1);
}

int main()
{
  fin >> n >> m;
  for (int i = 1; i < n; ++i)
  {
    fin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (int i = 1; i <= n; ++i)
  {
    fin >> a[i];
    a[i]++;
  }

  deep[1] = 1;

  DFS(1);

  RMQ();

  for (int i = 1; i <= m; ++i)
  {
    fin >> x >> y >> c;
    ++c;
    q[x].push_back({i, c});
    q[y].push_back({i, c});
    int z = lca(x, y);
    scz[z].push_back({i, c});
  }

  used.reset();

  solve(1);

  for (int i = 1; i <= m; ++i)
    fout << s[i] << "\n";

  fout.close();
  return 0;