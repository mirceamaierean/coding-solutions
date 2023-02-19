#include <fstream>
#include <limits.h>
#include <algorithm>
using namespace std;

ifstream fin("carnati.in");
ofstream fout("carnati.out");

const long long NMAX = 2001;

long long max(long long a, long long b)
{
  return (a > b) ? a : b;
}

long long min(long long a, long long b)
{
  return (a < b) ? a : b;
}

struct carnati
{
  long long t, p;
};

inline bool cmp(carnati a, carnati b)
{
  return a.t < b.t;
}

carnati a[NMAX];

int n, c;
long long maxi, nr;

int main()
{
  fin >> n >> c;

  for (int i = 1; i <= n; ++i)
    fin >> a[i].t >> a[i].p;

  sort(a + 1, a + n + 1, cmp);

  for (int i = 1; i <= n; ++i)
  {
    long long x = a[i].p;
    long long t = 0, p = -2000000001;

    for (int j = 1; j <= n; ++j)
    {
      if (a[j].p >= x)
      {
        if (p + x - (a[j].t - t) * c < x - c)
          p = x - c;
        else
          p += x - (a[j].t - t) * c;
        t = a[j].t;
        maxi = max(maxi, p);
      }
    }
  }

  fout << maxi << "\n";
  return 0;
}