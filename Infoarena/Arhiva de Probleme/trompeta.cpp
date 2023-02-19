#include <fstream>
#include <vector>

using namespace std;

char trompeta[1000005];

ifstream cin("trompeta.in");
ofstream cout("trompeta.out");

int main()
{
  int cnt = 1, n, m, lib;
  char a;

  cin >> n >> m;
  cin >> a;

  trompeta[0] = a;
  lib = m - 1;
  --n;

  while (n)
  {
    cin >> a;
    if (lib == n)
    {
      trompeta[cnt] = a;
      ++cnt;
    }
    else
    {
      --cnt;
      while (cnt >= 0 && trompeta[cnt] < a && lib < n)
      {
        --cnt;
        ++lib;
      }
      ++cnt;
      if (lib)
      {
        trompeta[cnt] = a;
        ++cnt;
      }
    }
    lib = m - cnt;
    --n;
  }

  cout << trompeta;

  return 0;
}