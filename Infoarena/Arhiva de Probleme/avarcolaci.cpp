#include <fstream>
#include <bitset>
#include <vector>
#include <unordered_map>

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
  InParser(const char *name)
  {
    buff = new char[4096];
    sp = 4095;
    fin = fopen(name, "r");
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

InParser fin("avarcolaci.in");
InParser fin2("avarcolaci.in");
ofstream fout("avarcolaci.out");

int cand[20];

int main()
{
  int n, t;
  fin >> t;

  while (t)
  {
    int ap = 0, el = 0, x;
    fin >> n;
    for (int i = 1; i <= 2 * n; ++i)
    {
      fin >> x;
      if (ap == 0)
      {
        ++ap;
        el = x;
      }
      else if (x == el)
        ++ap;
      else
        --ap;
    }
    cand[t] = el;
    t--;
  }

  fin2 >> t;

  while (t)
  {
    int x, cnt = 0;
    fin2 >> n;
    for (int i = 1; i <= 2 * n; ++i)
    {
      fin2 >> x;
      if (x == cand[t])
        ++cnt;
    }
    if (cnt > n)
      fout << cand[t] << "\n";
    else
      fout << "Mozart\n";
    t--;
  }

  return 0;
}
