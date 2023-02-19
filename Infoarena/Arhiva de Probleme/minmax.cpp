#include <fstream>
#include <algorithm>
#include <vector>
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

InParser fin("minmax.in");
ofstream fout("minmax.out");

vector<int> v;

int n;

unsigned long long s;

void solve(int st, int dr)
{
  if (st > dr)
    return;
  s += v[dr] - v[st];
  fout << s << "\n";
  solve(st + 1, dr - 1);
  s -= (v[dr] - v[st]);
  if (st < dr)
    fout << s << "\n";
}

int main()
{
  fin >> n;
  v.resize(n);

  for (int i = 0; i < n; ++i)
    fin >> v[i];

  sort(v.begin(), v.end());

  int st = 1, dr = n;

  solve(0, n - 1);

  fout.close();
  return 0;
}
