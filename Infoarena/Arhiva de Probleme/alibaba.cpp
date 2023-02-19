#include <fstream>
#include <vector>
using namespace std;

char st[10005];

ifstream fin("alibaba.in");
ofstream fout("alibaba.out");

int main()
{
  int cnt = 1, n, m, lib;
  char a;

  fin >> n >> m;

  m = n - m;

  fin >> a;

  st[0] = a;
  lib = m - 1;
  --n;

  while (n)
  {
    fin >> a;
    if (lib == n)
    {
      st[cnt] = a;
      ++cnt;
    }
    else
    {
      --cnt;
      while (cnt >= 0 && st[cnt] < a && lib < n)
      {
        --cnt;
        ++lib;
      }
      ++cnt;
      if (lib)
      {
        st[cnt] = a;
        ++cnt;
      }
    }
    lib = m - cnt;
    --n;
  }
  fout << st;
  return 0;
}