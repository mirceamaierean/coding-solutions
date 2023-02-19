#include <fstream>
#include <iostream>
#include <bitset>
#include <vector>
#include <string.h>

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
    int sgn = 1;
    char c;
    while (!isdigit(c = read()) && c != '-')
      ;
    if (c == '-')
    {
      n = 0;
      sgn = -1;
    }
    else
      n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    n *= sgn;
    return *this;
  }
};

InParser fin("treegcd.in");
std::ofstream fout("treegcd.out");

const int MOD = 1000000007;
const int NMAX = 10005;
const int GMAX = 105;

int ciur[NMAX], Div[NMAX];

int n, m;

struct nod
{
  long long dp[NMAX];
  std::vector<int> v;
};

nod G[GMAX];

int ndiv(int x)
{
  if (x == 1)
    return 0;

  int d = ciur[x];

  if ((x / d) % d == 0)
    return -1;

  int ans = ndiv(x / ciur[x]);

  if (ans == -1)
    return -1;

  return ans + 1;
}

void precalc()
{
  for (int i = 2; i <= m; ++i)
    if (ciur[i] == 0)
    {
      ciur[i] = i;
      for (int j = i * i; j <= m; j += i)
        if (ciur[j] == 0)
          ciur[j] = i;
    }

  for (int i = 2; i <= m; ++i)
    Div[i] = ndiv(i);
}

void calc(long long dp[])
{
  for (int i = 1; i <= m; ++i)
  {
    for (int j = 2 * i; j <= m; j += i)
    {
      dp[i] += dp[j];
      if (dp[i] > MOD)
        dp[i] -= MOD;
    }
  }

  long long aux[NMAX];

  memset(aux, 0, sizeof aux);

  aux[1] = dp[1];

  for (int i = 2; i <= m; ++i)
  {
    if (Div[i] == -1)
      continue;

    if (!(Div[i] & 1))
      dp[i] = MOD - dp[i];

    for (int j = i; j <= m; j += i)
    {
      aux[j] += dp[i];
      if (aux[j] > MOD)
        aux[j] -= MOD;
    }
  }

  for (int i = 1; i <= m; ++i)
    dp[i] = aux[i];
}

int x, y;

void DFS(int node, int x)
{
  G[node].dp[1] = 0;

  for (int i = 2; i <= m; ++i)
    G[node].dp[i] = 1;

  for (auto y : G[node].v)
  {
    if (y == x)
      continue;

    DFS(y, node);

    for (int i = 2; i <= m; ++i)
    {
      G[node].dp[i] *= G[y].dp[i];
      G[node].dp[i] %= MOD;
    }
  }

  calc(G[node].dp);
}

int main()
{
  fin >> n >> m;
  precalc();
  for (int i = 1; i < n; ++i)
  {
    fin >> x >> y;
    G[x].v.push_back(y);
    G[y].v.push_back(x);
  }
  DFS(1, 0);
  fout << G[1].dp[1] << '\n';
  fout.close();
  return 0;
}
