#include <fstream>
#include <iomanip>
using namespace std;

ifstream fin("albume.in");
ofstream fout("albume.out");

long double sol = 1;
int c, k, q, a, b;

int main()
{
  fin >> c >> k >> q;
  a = k * (c - 1) - q + 1;
  b = k * c - q + 1;
  while (q--)
  {
    long double r = (double)a / (double)b;
    sol *= r;
    a++;
    b++;
  }
  long double sol_finish = c * (1.0 - sol);
  fout << fixed << setprecision(9) << sol_finish << "\n";
  return 0;
}
