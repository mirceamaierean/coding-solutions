#include <fstream>
#include <deque>
#include <algorithm>
#include <limits.h>
using namespace std;

ifstream fin("calcule.in");
ofstream fout("calcule.out");

const int NMAX = 50005;
const int MOD = 20011;
int fr[NMAX];

int s[2 * NMAX];

int n, k, m;

int binary_search(int x)
{
  int st = 1, dr = m, poz = -1;
  while (st <= dr)
  {
    int mid = (st + dr) / 2;
    if (x > s[mid])
    {
      poz = mid;
      dr = mid - 1;
    }
    else
      st = mid + 1;
  }
  return poz;
}

int a, rest;
long long t;

int main()
{
  fr[0] = 1;
  fin >> n >> k;

  for (int i = 1; i <= n; ++i)
  {
    fin >> a;
    int poz = binary_search(a);
    if (poz == -1)
      s[++m] = a;
    else
      s[poz] = a;
    rest = (rest + a) % k;
    fr[rest]++;
  }
  for (int i = 0; i < k; ++i)
    t = (t + 1LL * fr[i] * (fr[i] - 1) / 2) % MOD;

  fout << m << "\n"
       << t << "\n";

  return 0;
}
