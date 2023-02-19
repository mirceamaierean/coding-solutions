#include <fstream>
#include <string.h>
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
InParser fin("gradina3.in");
ofstream fout("gradina3.out");

const int NMAX = 1002;

int a[NMAX][NMAX], n, k, p, maxi, cnt;

int main()
{
  int i, j;
  fin >> n >> p >> k;
  while (p--)
  {
    fin >> i >> j;
    a[i][j]++;
  }

  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

  for (i = k; i <= n; ++i)
    for (j = k; j <= n; ++j)
    {
      int val = a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k];
      if (val > maxi)
      {
        maxi = val;
        cnt = 1;
      }
      else if (val == maxi)
        cnt++;
    }

  fout << maxi << "\n"
       << cnt << "\n";
  fout.close();
  return 0;
}
