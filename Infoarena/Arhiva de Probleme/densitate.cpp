#include <fstream>
#include <vector>
#include <string.h>

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
    int sgn = 1;
    char c;
    while (!isdigit(c = read()) && c != '-')
      ;
    if (c == '-')
    {
      n = 0;
      sgn = -1;
    }
    else
      n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    n *= sgn;
    return *this;
  }
};

InParser fin("densitate.in");
std::ofstream fout("densitate.out");

const int NMAX = 5e5 + 2;
int ciur[NMAX], n, q, a, b;

void doIt()
{
  for (int i = 4; i < NMAX; i += 2)
    ciur[i] = 1;

  for (int i = 3; i * i <= NMAX; i += 2)
    if (ciur[i] == 0)
      for (int j = i * i; j < NMAX; j += i)
        ciur[j] = 1;

  for (int i = 2; i < NMAX; ++i)
    ciur[i] = 1 - ciur[i];

  for (int i = 1; i < NMAX; ++i)
    ciur[i] += ciur[i - 1];
}

int main()
{
  doIt();

  fin >> n >> q;

  while (q--)
  {
    fin >> a >> b;
    fout << ciur[b] - ciur[a - 1] << "\n";
  }

  fout.close();
  return 0;
}