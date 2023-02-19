#include <fstream>
#include <iostream>
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

InParser fin("cmmdc2.in");
ofstream fout("cmmdc2.out");

const int NMAX = 1e6 + 2;

int fr[NMAX], d[NMAX], maxi, n, k, a, cmax = 1, cnt;

int main()
{
  fin >> n >> k;
  for (int i = 1; i <= n; ++i)
  {
    fin >> a;
    if (a > maxi)
      maxi = a;
    ++fr[a];
  }

  d[1] = maxi;

  for (int i = 2; i <= maxi; ++i)
    for (int j = i; j <= maxi; j += i)
      if (fr[j] && j > d[i])
        d[i] = j;

  for (int i = 2; i <= maxi; ++i)
  {
    cnt = 0;
    for (int j = i; j <= maxi; j += i)
      cnt += fr[j];
    if (cnt >= k)
      cmax = i;
  }
  fout << cmax << "\n";
  int st = d[cmax];
  while (k > 0)
  {
    while (fr[st] && k)
    {
      fout << st << " ";
      --fr[st];
      --k;
    }
    st -= cmax;
  }
  fout.close();
  return 0;
}
