#include <fstream>

#define mod 9001

using namespace std;

ifstream fin("flori4.in");
ofstream fout("flori4.out");

int n, a, b, c;
int main()
{
  fin >> n;
  a = b = 1;

  for (int i = 3; i <= n + 2; ++i)
  {
    c = a + b;
    if (c > mod)
      c -= mod;
    a = b;
    b = c;
  }

  fout << b - 1 << '\n';
  return 0;
}
