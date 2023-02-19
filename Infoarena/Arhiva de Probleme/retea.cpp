#include <fstream>
#include <string.h>
#include <queue>
#include <vector>
#include <iomanip>
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
  InParser &operator>>(long long &n)
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
InParser fin("retea.in");
ofstream fout("retea.out");

const int NMAX = 1002;
const int oo = 0x3f3f3f3f;
int n, m, k, x, y;
long long d[NMAX][11], z;

typedef pair<int, int> p;
typedef pair<int, long long> pd;
typedef pair<long long, p> pp;
vector<pd> g[NMAX];

void Dijkstra()
{
  priority_queue<pp, vector<pp>, greater<pp>> q;

  d[1][0] = 0;

  q.push({0, {1, 0}});

  while (!q.empty())
  {
    pp a = q.top(), b;
    q.pop();

    if (a.first != d[a.second.first][a.second.second])
      continue;

    for (auto i : g[a.second.first])
    {
      long long c = i.second;
      for (int j = a.second.second; j <= k; ++j)
      {
        b = {a.first + c, {i.first, j}};
        if (d[i.first][j] > b.first)
        {
          d[i.first][j] = b.first;
          q.push(b);
        }
        c >>= 1;
      }
    }
  }
}

int main()
{
  fin >> n >> m >> k;

  while (m--)
  {
    fin >> x >> y >> z;
    z <<= 10;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  memset(d, oo, sizeof d);

  Dijkstra();

  double r = d[n][k];

  r /= 1024;

  fout << fixed << setprecision(4) << r << "\n";

  return 0;
}