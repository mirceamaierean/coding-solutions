#include <fstream>
#include <cmath>
using namespace std;

ifstream fin("patrat2.in");
ofstream fout("patrat2.out");

int n;

int main()
{
  fin >> n;
  while (n)
  {
    int v = sqrt(n);
    fout << v << "\n";
    n -= v * v;
  }
  return 0;
}
