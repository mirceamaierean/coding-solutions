#include <fstream>
#include <map>
using namespace std;

ifstream fin("teste.in");
ofstream fout("teste.out");

int n, k;

const int MOD = 1e9 + 7;

map<int, int> cnt;

void desc(int a, int plus)
{
  int d = 2;
  while (d * d <= a)
  {
    while (a % d == 0)
    {
      if (cnt.find(d) == cnt.end())
        cnt[d] = plus;

      else
        cnt[d] += plus;

      if (cnt[d] >= MOD)
        cnt[d] -= MOD;

      a /= d;
    }
    ++d;
  }
  if (a > 1)
  {
    if (cnt.find(a) == cnt.end())
      cnt[a] = plus;

    else
      cnt[a] += plus;

    if (cnt[a] >= MOD)
      cnt[a] -= MOD;
  }
}

int main()
{
  fin >> n >> k;
  desc(n, 1);
  if (k & 1)
  {
    desc(((k + 1) >> 1), 1);
    desc(k, 1);
  }
  else
  {
    desc((k + 1), 1);
    desc((k >> 1), 1);
  }

  desc(k, n - 1);

  unsigned long long ans = 1;
  for (auto i : cnt)
  {
    ans *= 1LL * (i.second + 1);
    ans %= MOD;
  }

  fout << ans << "\n";

  fout.close();
  return 0;
}
