#include <fstream>
#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;

const int NMAX = 1e6;
const long long as = 1e12 + 2;

class parsare
{
private:
  FILE *fin;
  int sp;
  char *buff;
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
  parsare(const char *nume)
  {
    sp = 4095;
    fin = fopen(nume, "r");
    buff = new char[4096];
  }
  parsare &operator>>(long long &n)
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

parsare fin("asi.in");
ofstream fout("asi.out");

vector<long long> v;

bitset<NMAX + 5> ciur;
long long a, b, q;

int main()
{
  for (int i = 4; i <= NMAX; i += 2)
    ciur[i] = 1;

  for (long long i = 4; i <= as; i *= 2)
    v.push_back(i);

  for (int i = 3; i <= NMAX; i += 2)
    if (ciur[i] == 0)
    {
      for (long long j = 1LL * i * i; j <= NMAX; j += i)
        ciur[j] = 1;

      for (long long j = 1LL * i * i; j <= as; j *= 1LL * i)
        v.push_back(j);
    }

  sort(v.begin(), v.end());

  fin >> q;

  while (q--)
  {
    fin >> a >> b;
    fout << upper_bound(v.begin(), v.end(), b) - upper_bound(v.begin(), v.end(), a - 1) << "\n";
  }
  return 0;
}
