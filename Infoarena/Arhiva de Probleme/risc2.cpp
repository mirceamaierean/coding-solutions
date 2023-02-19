#include <fstream>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;

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

InParser fin("risc2.in");
ofstream fout("risc2.out");

typedef vector<int> VI;

VI a, b, fr;

int n, hmax, pmax = -1, cer;

int main()
{
  fin >> cer >> n;
  a = VI(n);
  for (int i = 0; i < n; ++i)
  {
    fin >> a[i];
    if (a[i] > hmax)
    {
      hmax = a[i];
      pmax = i;
    }
  }

  if (cer == 1)
  {
    bool ok = true;
    for (int i = 0; i < n && ok; ++i)
    {
      if (i && i <= pmax && a[i - 1] > a[i])
        ok = false;

      if (i > pmax && a[i - 1] < a[i])
        ok = false;
    }

    if (ok && pmax && a[pmax - 1] > a[n - 1])
      ok = false;

    if (ok)
      fout << pmax + 1 << "\n";
    else
      fout << "-1\n";
  }

  else
  {
    fr = VI(hmax + 1);
    b = a;

    sort(b.begin(), b.end());

    int cntasc(0), cntdesc(0), k(0);

    for (int i(0), j(0); i < n; ++i)
    {
      if (a[i] == b[j])
      {
        ++cntasc;
        ++j;
      }
      if (i == pmax)
        k = cntasc;
    }

    for (int i(pmax), j(n - 1); i < n; ++i)
    {
      if (a[i] == b[j])
      {
        cntdesc++;
        --j;
      }
    }
    fout << n - max(cntasc, k + cntdesc) << "\n";
  }
  return 0;
}
