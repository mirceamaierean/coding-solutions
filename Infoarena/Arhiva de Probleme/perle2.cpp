#include <fstream>

using namespace std;

ifstream fin("perle2.in");
ofstream fout("perle2.out");

const int NMAX = 1e5 + 2;

int main()
{
  int a, k, maxi = 0, n, crt = -NMAX;
  fin >> n >> k;
  for (int i = 1; i <= n; ++i)
  {
    fin >> a;
    a -= k;
    if (crt < 0)
      crt = a;
    else
      crt += a;
    if (crt > maxi)
      maxi = crt;
  }

  fout << maxi << "\n";

  return 0;
}
