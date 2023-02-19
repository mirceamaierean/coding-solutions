#include <fstream>

using namespace std;

ifstream fin("modulo.in");
ofstream fout("modulo.out");

unsigned long long n, p, nr = 1;

int main()
{
  int c;
  fin >> n >> p >> c;
  n %= c;
  while (p > 0)
  {
    if (p % 2 == 1)
    {
      nr = (nr * n) % c;
      p--;
    }
    else
    {
      n = (n * n) % c;
      p = p / 2;
    }
  }
  fout << nr;

  return 0;
}