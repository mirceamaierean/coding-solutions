#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;

const int NMAX = 5003;
const int QMAX = 1e5 + 2;
typedef pair<int, int> p;
int n, q, sol[QMAX], cnt[NMAX], t[NMAX];

vector<int> v;
vector<p> inv[NMAX];

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
    fin = fopen(nume, "r");
    buff = new char[4096];
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

InParser fin("inversari.in");
ofstream fout("inversari.out");

int a, b;

int main()
{
  fin >> n >> q;
  v.resize(n + 1);

  for (int i = 1; i <= n; ++i)
    fin >> v[i];

  for (int i = 1; i <= q; ++i)
  {
    fin >> a >> b;
    inv[a].push_back({b, i});
  }

  for (int i = n; i; --i)
  {
    for (int j = i + 1; j <= n; ++j)
    {
      if (v[i] > v[j])
        ++cnt[j];
    }

    for (int j = i + 1; j <= n; ++j)
      t[j] = t[j - 1] + cnt[j];

    for (size_t j = 0; j < inv[i].size(); ++j)
      sol[inv[i][j].second] = t[inv[i][j].first];
  }

  for (int i = 1; i <= q; ++i)
    fout << sol[i] << "\n";

  return 0;
