#include <fstream>
#include <vector>
#define LL unsigned long long
using namespace std;
ifstream cin("tnia.in");
ofstream cout("tnia.out");
vector<LL> v;
vector<LL> sum;
int bsearch1(int p, int u, int key)
{
  int m;
  while (p < u)
  {
    m = (p + u) / 2;
    if (v[m] <= key)
      p = m + 1;
    else
      u = m;
  }
  m = (p + u) / 2;
  if (v[m] > key)
    --m;
  return m;
}
int bsearch2(int p, int u, int key)
{
  int m;
  while (p < u)
  {
    m = (p + u) / 2;
    if (v[m] < key)
      p = m + 1;
    else
      u = m;
  }
  m = (p + u) / 2;
  if (v[m] < key)
    ++m;
  return m;
}
int main()
{
  int n, m;
  LL sume = 0, k;
  cin >> n >> m;
  v.push_back(0);
  sum.push_back(0);
  for (int i = 1; i <= n; ++i)
  {
    cin >> k;
    v.push_back(k);
    sume += k;
    sum.push_back(sume);
  }
  int q, a, b, c, d;
  cin >> q;
  for (int i = 1; i <= q; ++i)
  {
    cin >> a >> b >> c >> d;
    int st = bsearch2(a, c, b), dr = bsearch1(a, c, d);
    if (st > c)
      cout << 0 << "\n";
    else
    {
      LL suma = (LL)(c - dr) * (LL)(d - b + 1);
      suma -= (LL)(b - 1) * (LL)(dr - st + 1);
      suma += (sum[dr] - sum[st - 1]);
      cout << suma << "\n";
    }
  }
  return 0;
}
