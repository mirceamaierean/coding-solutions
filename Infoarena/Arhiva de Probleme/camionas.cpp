#include <fstream>
#include <vector>
#include <queue>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

const int NMAX = 50003;
const int oo = 0x3f3f3f3f;

vector<pair<int, int>> v[NMAX];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

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
    sp = 4095;
    buff = new char[4096];
    fin = fopen(nume, "r");
  }
  InParser &operator>>(int &n)
  {
    char c;
    n = 0;
    while (!isdigit(c = read()))
      ;
    n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    return *this;
  }
};

InParser fin("camionas.in");
ofstream fout("camionas.out");

int n, m, g, x, y, z, dp[NMAX];

void BFS()
{
  while (!q.empty())
  {
    int x = q.top().second;
    if (x == n)
    {
      fout << dp[n] << "\n";
      return;
    }
    q.pop();
    for (size_t i = 0; i < v[x].size(); ++i)
    {
      int crt = v[x][i].first;
      bool cost = v[x][i].second < g;
      if (dp[crt] > dp[x] + cost)
      {
        dp[crt] = dp[x] + cost;
        q.push({dp[crt], crt});
      }
    }
  }
  fout << dp[n] << "\n";
}

int main()
{
  fin >> n >> m >> g;
  for (int i = 1; i <= m; ++i)
  {
    fin >> x >> y >> z;
    v[x].push_back({y, z});
    v[y].push_back({x, z});
  }
  memset(dp, oo, sizeof dp);
  dp[1] = 0;
  q.push({0, 1});
  BFS();
  return 0;
}
