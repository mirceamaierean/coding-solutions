#include <fstream>

using namespace std;

ifstream fin("trenul.in");
ofstream fout("trenul.out");

int ls, n, m, a;

int main()
{
  fin >> n >> m;

  ls = 1;

  while (m--)
  {
    fin >> a;
    if (a & 1)
    {
      for (int i = ls; i < ls + a; ++i)
        fout << i << " ";
      ls += a;
    }
    else
    {
      for (int i = n - a + 1; i <= n; ++i)
        fout << i << " ";
      n -= a;
    }
    fout << "\n";
  }
  fout.close();
  return 0;
}
