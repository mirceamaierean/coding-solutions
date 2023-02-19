#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("abx.in");
ofstream fout("abx.out");

int n;
unsigned long long m, a;
bool fr[65];

unsigned long long lgput(unsigned long long m, int b)
{
  unsigned long long p = 1;
  while (b)
  {
    if (b & 1ULL)
    {
      p *= m;
      --b;
    }
    else
    {
      m *= m;
      b /= 2;
    }
  }
  return p;
}

unsigned long long cautb(unsigned long long x, int put)
{
  unsigned long long st = 1, dr = pow(x, 1.0 / put);
  while (st <= dr)
  {
    int mij = (1ULL * st + dr) / 2;
    if (lgput(mij, put) > x)
      dr = mij - 1;
    else
      st = mij + 1;
  }
  return dr;
}

int main()
{
  fr[2] = fr[3] = fr[5] = fr[7] = fr[11] = fr[13] = fr[17] = fr[19] = fr[23] = fr[29] = fr[31] = fr[37] = fr[41] = fr[43] = fr[47] = fr[51] = fr[53] = fr[59] = fr[61] = 1;

  fin >> n >> m;

  while (n--)
  {
    fin >> a;
    unsigned long long dif = 1ULL << 63, val, cr;
    for (int i = 2; i <= 61; ++i)
      if (fr[i])
      {
        unsigned long long b = cautb(a, i);
        cr = lgput(b, i);

        if (a - cr <= dif)
        {
          dif = a - cr;
          val = cr;
        }
        cr = lgput(b + 1, i);

        if (cr <= m && cr - a < dif)
        {
          dif = cr - a;
          val = cr;
        }
      }
    fout << val << "\n";
  }

  return 0;
}