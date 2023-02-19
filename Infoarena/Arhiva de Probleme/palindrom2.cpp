#include <fstream>

using namespace std;

ifstream fin("palindrom2.in");
ofstream fout("palindrom2.out");

string a;
int n;

bool check(int p)
{
  int dr = n - 1;
  while (p <= dr && dr >= 0 && p < n && a[p] == a[dr])
  {
    ++p;
    --dr;
  }
  return p > dr;
}
int main()
{
  fin >> a;
  n = a.size();

  int poz = n - 1;

  for (int i = 0; i < n; ++i)
    if (check(i))
    {
      poz = i;
      break;
    }
  fout << a;
  for (int i = poz - 1; i >= 0; --i)
    fout << a[i];
  fout.close();
  return 0;
}