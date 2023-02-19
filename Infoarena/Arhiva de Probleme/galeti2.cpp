#include <fstream>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;

int n, poz;
long long e;

ifstream fin("galeti2.in");
ofstream fout("galeti2.out");

const int NMAX = 1e6 + 1;

int main()
{
  fin >> n >> e;

  e++;
  e -= n;

  long long val = sqrt(e) - 1;
  while (val * (val + 1) >> 1LL <= e)
    ++val;

  --val;

  e -= val * (val + 1) >> 1LL;

  ++e;

  for (int i = val + 2; i > e; --i)
    fout << i << " " << i - 1 << '\n';

  if (val + 3 <= n)
    fout << val + 3 << " " << e << "\n";

  for (int i = e; i > 1; --i)
    fout << i << " " << i - 1 << '\n';

  for (int i = val + 4; i <= n; ++i)
    fout << i << " " << 1 << "\n";

  return 0;
}
