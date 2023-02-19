#include <fstream>
#include <deque>
#include <algorithm>
#include <bitset>
using namespace std;

ifstream fin("interclasare.in");
ofstream fout("interclasare.out");

const int NMAX = 10001;
const int oo = 1e9;

int a1[NMAX], a2[NMAX], b[NMAX], d[NMAX];
bitset<NMAX> fr1;
bitset<NMAX> fr2;

int lis(int n, int a[], bitset<NMAX> &fr)
{
  int maxi = 0;
  for (int i = 1; i <= n; ++i)
  {
    b[i] = oo;
    d[i] = 0;
  }

  for (int i = 1; i <= n; ++i)
  {
    d[i] = upper_bound(b + 1, b + n + 1, a[i]) - b;
    if (d[i] > maxi)
      maxi = d[i];
    b[d[i]] = a[i];
  }

  int cnt = maxi;

  for (int i = n; i; --i)
  {
    if (d[i] == maxi)
    {
      fr[i] = 1;
      maxi--;
    }
  }

  return cnt;
}
int main()
{
  int n, m;

  fin >> n;
  for (int i = 1; i <= n; ++i)
    fin >> a1[i];

  fin >> m;

  for (int i = 1; i <= m; ++i)
    fin >> a2[i];
  fout << lis(n, a1, fr1) + lis(m, a2, fr2) << "\n";

  int i = 1, j = 1;

  while (i <= n || j <= m)
  {
    if (i <= n)
    {
      if (j <= m)
      {
        if (fr1[i] && fr2[j])
        {
          if (a1[i] < a2[j])
          {
            fout << a1[i] << " ";
            ++i;
          }
          else
          {
            fout << a2[j] << " ";
            ++j;
          }
        }
        else if (fr1[i] == 0)
        {
          fout << a1[i] << " ";
          ++i;
        }
        else
        {
          fout << a2[j] << " ";
          ++j;
        }
      }
      else
      {
        fout << a1[i] << " ";
        ++i;
      }
    }
    else
    {
      fout << a2[j] << " ";
      ++j;
    }
  }
  return 0;
}
