#include <fstream>
#include <algorithm>
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
InParser fin("conexidad.in");
ofstream fout("conexidad.out");

const int NMAX = 102;
bitset<NMAX> viz;

int a, b, n, m, extra[NMAX], max_extra, ind;

vector<int> g[NMAX];
vector<int> conexa[NMAX];

vector<pair<int, int>> p;

void DFS(int x)
{
  viz[x] = 1;
  conexa[ind].push_back(x);
  for (size_t i = 0; i < g[x].size(); ++i)
    if (viz[g[x][i]] == 0)
      DFS(g[x][i]);
}

inline bool cmp(vector<int> a, vector<int> b)
{
  return a.size() > b.size();
}
int main()
{
  extra[0] = 0x3f3f3f;

  max_extra = 0;

  fin >> n >> m;

  for (int i = 1; i <= m; ++i)
  {
    fin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for (int i = 1; i <= n; ++i)
  {
    if (viz[i] == 0)
    {
      DFS(i);
      ++ind;
    }
  }

  sort(conexa, conexa + ind, cmp);

  for (int i = 1; i < ind; ++i)
  {
    int poz = 0;
    for (size_t j = 0; j < conexa[0].size(); ++j)
    {
      int y = conexa[0][j];
      if (extra[y] < extra[poz])
        poz = y;
    }
    extra[poz]++;
    extra[conexa[i][0]]++;
    p.push_back({conexa[i][0], poz});
    for (size_t j = 0; j < conexa[i].size(); ++j)
      conexa[0].push_back(conexa[i][j]);
  }

  for (int i = 1; i <= n; ++i)
    if (extra[i] > max_extra)
      max_extra = extra[i];

  fout << max_extra << "\n"
       << ind - 1 << "\n";

  for (size_t i = 0; i < p.size(); ++i)
    fout << p[i].first << " " << p[i].second << "\n";

  fout.close();
  return 0;
}
