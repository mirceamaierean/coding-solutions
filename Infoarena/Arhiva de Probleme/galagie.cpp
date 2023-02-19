#include <fstream>
#include <algorithm>
#define MOD 1000000007
using namespace std;

ifstream fin("galagie.in");
ofstream fout("galagie.out");

long long a[100002], n;

int main()
{
  fin >> n;
  for (int i = 1; i <= n; ++i)
    fin >> a[i];
  sort(a + 1, a + n + 1);
  long long suma = 0;
  for (int i = 1; i <= n; ++i)
  {
    suma += a[i] * (i - 1) * 2;
    suma -= a[i] * (n - i) * 2;
    suma %= MOD;
  }
  fout << suma << "\n";
  return 0;
}
