#include <fstream>
#include <queue>
using namespace std;

ifstream fin("permutariab.in");
ofstream fout("permutariab.out");

const int NMAX = 1e5 + 2;

int aib[NMAX], n, a[NMAX], b[NMAX];
unsigned long long cnt;

void update(int p, int val)
{
  for (int i = p; i <= n; i += i & -i)
    aib[i] += val;
}

unsigned long long query(int p)
{
  unsigned long long suma = 0;
  for (int i = p; i; i -= i & -i)
    suma += aib[i];
  return suma;
}

int main()
{
  fin >> n;
  for (int i = 1; i <= n; ++i)
    fin >> a[i];

  for (int i = 1; i <= n; ++i)
    fin >> b[i];

  int poz[NMAX];

  for (int i = 1; i <= n; ++i)
    poz[a[i]] = i;

  for (int i = 1; i <= n; ++i)
  {
    int p = poz[b[i]];
    cnt += p - 1 - query(p);
    update(p, 1);
  }

  fout << cnt << "\n";
  return 0;
}
