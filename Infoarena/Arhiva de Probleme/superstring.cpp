#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;

ifstream fin("superstring.in");
ofstream fout("superstring.out");

string a, b;

const int NMAX = 1e6 + 2;
int t, pib[NMAX], pia[NMAX], l_a, l_b;
;

inline void make_prefix_a()
{
  int k = 0;
  for (int i = 2; i <= l_a; ++i)
  {
    while (k && a[k + 1] != a[i])
      k = pia[k];
    if (a[k + 1] == a[i])
      ++k;
    pia[i] = k;
  }
}

inline void make_prefix_b()
{
  int k = 0;
  for (int i = 2; i <= l_b; ++i)
  {
    while (k && b[k + 1] != b[i])
      k = pib[k];
    if (b[k + 1] == b[i])
      ++k;
    pib[i] = k;
  }
}

inline int cmp1()
{
  int k = 0;
  for (int i = 1; i <= l_b; ++i)
  {
    while (k && a[k + 1] != b[i])
      k = pia[k];
    if (a[k + 1] == b[i])
      ++k;
    if (k == l_a)
      return l_a;
  }
  return k;
}

inline int cmp2()
{
  int k = 0;
  for (int i = 1; i <= l_a; ++i)
  {
    while (k && b[k + 1] != a[i])
      k = pib[k];
    if (b[k + 1] == a[i])
      ++k;
    if (k == l_b)
      return l_b;
  }
  return k;
}

int main()
{
  fin >> t;
  while (t--)
  {
    fin >> a >> b;

    l_a = a.size();
    l_b = b.size();

    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);

    memset(pia, 0, sizeof pia);
    memset(pib, 0, sizeof pib);

    make_prefix_a();
    make_prefix_b();

    int m = max(cmp1(), cmp2());
    fout << l_a + l_b - m << "\n";
  }
  return 0;
}
