#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#define x first.first
#define y first.second
#define z second
using namespace std;

class InParser
{
#pragma warning(disable : 4996)
private:
  FILE *fin;
  char *buff;
  int sp;

public:
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

InParser fin("ramen.in");
ofstream fout("ramen.out");

typedef pair<pair<int, int>, int> _tuple;

set<_tuple> s1;
set<int> s2;

const int NMAX = 1e5 + 1;

int n, d, t, p, q[NMAX];

int main()
{
  fin >> n >> d;

  for (int i = 1; i <= n; ++i)
  {
    fin >> t >> p;
    s2.insert(t);
    s1.insert({{p, t}, i});
  }

  for (auto i : s1)
  {
    set<int>::iterator it = s2.lower_bound(i.y - i.x - d);
    q[i.z] = *it + d + i.x;
    s2.erase(*it);
  }

  for (int i = 1; i <= n; ++i)
    fout << q[i] << "\n";

  fout.close();
  return 0;
}
