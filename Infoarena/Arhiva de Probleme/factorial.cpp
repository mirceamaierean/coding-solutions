#include <fstream>
#define NMAX 1000000000

using namespace std;

long long n, suma;

long long numarzero(long long n)
{
  if (n == 0)
    return 1;
  suma = 0;
  for (long long i = 5; n / i >= 1; i *= 5)
    suma += n / i;
  return suma;
}

long long cautbin(long long n)
{
  long long st = 0, dr = NMAX, m;
  while (st <= dr)
  {
    m = (st + dr) / 2;
    long long zero = numarzero(m);
    if (zero == n)
    {
      long long x = m - 1;
      while (numarzero(x) == zero)
        x--;
      return x + 1;
    }
    else if (zero < n)
      st = m + 1;
    else
      dr = m - 1;
  }
  return -1;
}

ifstream cin("fact.in");
ofstream cout("fact.out");

int main()
{
  cin >> n;
  cout << cautbin(n);
  return 0;
}