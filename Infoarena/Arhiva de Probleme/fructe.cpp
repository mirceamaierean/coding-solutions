#include <fstream>

using namespace std;

ifstream fin("fructe.in");
ofstream fout("fructe.out");

int n, p, b;

int main()
{
  fin >> n;
  while (n--)
  {
    fin >> p >> b;
    fout << (b & 1) << "\n";
  }
  return 0;
}