#include <fstream>

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

InParser fin("crescator3.in");
ofstream fout("crescator3.out");

const int NMAX = 3 * 1e5 + 2;

int fr[NMAX], mini, maxi, n, a, cnt;

int s_cifre(int x)
{
  int s(0);
  while (x)
  {
    s += x % 10;
    x /= 10;
  }
  return s;
}

int main()
{
  fin >> n >> a;
  mini = a;
  maxi = a;
  fr[0] = 1;
  for (int i = 2; i < n; ++i)
  {
    fin >> a;
    ++fr[a - mini];
  }
  fin >> maxi;
  ++fr[maxi - mini];
  a = mini;
  cnt = fr[0];
  fr[0] = 0;
  for (int i = 2; i <= n; ++i)
  {
    a += s_cifre(a);
    if (a <= maxi)
    {
      cnt += fr[a - mini];
      fr[a - mini] = 0;
    }
    else
      break;
  }
  fout << cnt << '\n';
  fout.close();
  return 0;
}
