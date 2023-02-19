#include <fstream>

using namespace std;

int main()
{
  ifstream cin("cifre5.in");
  ofstream cout("cifre5.out");
  char p;
  unsigned long long a;
  int cnt = 0;
  cin >> p;
  cin >> a;
  if (p == '1')
  {
    while (a)
    {
      if (a % 10 == 2 || a % 10 == 3 || a % 10 == 5)
        cnt += 5;
      else if (a % 10 == 9 || a % 10 == 6 || a % 10 == 0)
        cnt += 6;
      else if (a % 10 == 1)
        cnt += 2;
      else if (a % 10 == 4)
        cnt += 4;
      else if (a % 10 == 7)
        cnt += 3;
      else
        cnt += 7;
      a /= 10;
    }
    cout << cnt;
  }
  else
  {
    int v[25];
    unsigned long long b = a;
    unsigned long long nrfin = 1, dscz = 1;
    int cnt = 0;
    while (a)
    {
      if (a % 10 == 0 || a % 10 == 2 || a % 10 == 6 || a % 10 == 9)
      {
        nrfin *= 2;
        v[cnt] = 2;
      }
      else if (a % 10 == 3 || a % 10 == 4)
      {
        nrfin *= 3;
        v[cnt] = 3;
      }
      else if (a % 10 == 1)
      {
        nrfin *= 7;
        v[cnt] = 7;
      }
      else if (a % 10 == 5)
      {
        nrfin *= 4;
        v[cnt] = 4;
      }
      else if (a % 10 == 7)
      {
        nrfin *= 5;
        v[cnt] = 5;
      }
      else
        v[cnt] = 1;
      a /= 10;
      ++cnt;
    }
    if (b % 10 == 1 || b % 10 == 9)
      nrfin -= 2;
    else if (b % 10 == 7)
      nrfin -= 3;
    else
      nrfin--;
    b /= 10;
    cnt = 0;
    dscz = v[0];
    while (b)
    {
      if (b % 10 == 1 || b % 10 == 9)
        nrfin -= dscz;
      else if (b % 10 == 7)
        nrfin -= 2 * dscz;
      ++cnt;
      dscz *= v[cnt];
      b /= 10;
    }
    cout << nrfin;
  }
  return 0;
}
