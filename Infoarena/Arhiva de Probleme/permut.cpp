#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("permut.in");
ofstream fout("permut.out");

long long suma;

int n, x;

int main()
{
  fin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i)
    fin >> a[i];
  for (int i = 0; i < n; ++i)
    fin >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (int i = 0; i < n; ++i)
    suma += 1LL * a[i] * b[i];

  fout << suma << "\n";

  fout.close();
  return 0;
}
