#include <fstream>

using namespace std;

ifstream fin("joctv.in");
ofstream fout("joctv.out");

const int NMAX = 104;

int a[NMAX][NMAX], n, s[NMAX], x;

int main()
{
  fin >> n;
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      fin >> x;
      a[i][j] = a[i - 1][j] + x;
    }
  }
  int maxi = -1000000000;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
    {
      int s1 = 0, s2 = 0, mini = 1000000000;
      for (int k = 1; k <= n; ++k)
      {
        s[k] = a[i][k] - a[j - 1][k];
        s1 += s[k];
        if (mini > s2)
          mini = s2;
        if (maxi < s1 - mini)
          maxi = s1 - mini;
        s2 += s[k];
      }
    }
  fout << maxi << "\n";
  return 0;
}