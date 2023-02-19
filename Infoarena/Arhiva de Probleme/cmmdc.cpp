#include <fstream>

using namespace std;

ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");

int main()
{
  int a, b;

  fin >> a >> b;

  int r = 1;

  if (a < b)
    swap(a, b);

  while (r)
  {
    r = a % b;
    a = b;
    b = r;
  }

  if (a == 1)
    a = 0;

  fout << a << "\n";

  return 0;
}
