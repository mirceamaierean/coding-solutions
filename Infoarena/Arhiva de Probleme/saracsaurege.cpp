#include <fstream>
#include <algorithm>
using namespace std;

const int NMAX = 50005;
const int PMAX = 20;

int rmq[NMAX], a[NMAX], lg[NMAX], n, m;

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
InParser fin("saracsaurege.in");
ofstream fout("saracsaurege.out");

int main()
{
  fin >> n >> m;

  for (int i = 1; i <= n; ++i)
  {
    fin >> a[i];
    if (i > 1)
      lg[i] = lg[i / 2] + 1;
  }

  int dif, l, r, last(0);

  while (m--)
  {
    fin >> l >> r;
    dif = lg[r - l + 1];

    if (dif != last)
    {
      for (int i = 1; i <= n; ++i)
        rmq[i] = a[i];

      for (int i = 1; i <= dif; ++i)
        for (int j = 1; j <= n - (1 << i) + 1; ++j)
          rmq[j] = max(rmq[j], rmq[j + (1 << (i - 1))]);

      last = dif;
    }

    fout << max(rmq[l], rmq[r - (1 << dif) + 1]) << "\n";
  }

  return 0;
}
