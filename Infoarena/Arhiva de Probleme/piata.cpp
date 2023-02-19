#include <fstream>

using namespace std;

ifstream fin("piata.in");
ofstream fout("piata.out");

int n, im, jm, it, jt;

const int NMAX = 4 * 10e4 + 2;

int s[NMAX];

inline int transform(int n)
{
  int r = 0;
  while (n)
  {
    r += n % 10;
    n /= 10;
  }
  return r;
}

int main()
{
  fin >> n >> it >> jt >> im >> jm;

  for (int i = 1; i <= n; ++i)
    s[i] = transform(i);

  it = jt - it + 1;

  if (it <= 0)
    it += n;

  int intra = it + 1;
  if (intra > n)
    intra = 1;

  im = jt - im + 1;

  if (im <= 0)
    im += n;
  int iese = im;

  int suma = s[im];

  while (it != im)
  {
    suma += s[it];
    it--;
    if (it == 0)
      it = n;
  }

  int total = suma;

  while (jt != jm)
  {
    suma -= s[iese];
    iese++;
    if (iese > n)
      iese = 1;
    suma += s[intra];
    intra++;
    if (intra > n)
      intra = 1;
    total += suma;
    jt++;
  }

  fout << total << "\n";

  return 0;
}