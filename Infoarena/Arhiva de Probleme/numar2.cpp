#include <fstream>
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

InParser fin("numar2.in");
ofstream fout("numar2.out");

const int NMAX = 15e6 + 1;

bitset<NMAX> ok;

int n, m, a;
int main()
{
  fin >> n >> m >> a;
  int lim = m * a;
  for (int i = a; i <= lim; i += a)
    ok[i] = 1;
  n--;
  while (n--)
  {
    fin >> a;
    for (int i = a; i <= lim; i += a)
      ok[i] = 1;
  }

  for (int i = 1; i <= lim; ++i)
    if (ok[i])
    {
      m--;
      if (m == 0)
      {
        fout << i << "\n";
        return 0;
      }
    }
  fout.close();
  return 0;
}