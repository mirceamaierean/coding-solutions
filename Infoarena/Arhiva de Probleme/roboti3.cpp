#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
  ifstream cin("roboti3.in");
  ofstream cout("roboti3.out");
  long long a[100001], p[100001], cnt = 0;
  long n, i, max = 1, s, d, ns, nd;
  int serie, cs, antdr;
  char k;
  cin >> k;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  if (k == '1')
  {
    for (int i = 0; i < 2 * n - 2; ++i)
    {
      if (a[i % n] < a[(i + 1) % n])
        ++cnt;
      else
        cnt = 0;
      if (cnt > max)
        max = cnt;
      if (max == n - 1)
        break;
    }
    cout << max + 1;
  }
  else
  {
    sort(a, a + n);
    p[0] = a[0];
    s = 0;
    d = n;
    serie = 0;
    ns = 0;
    nd = 0;
    antdr = 0;
    for (i = 1; i <= n - 1; i++)
    {
      if (i < n - 1 && a[i] == a[i + 1] && a[i - 1] != a[i])
        cs = 1;
      else
        cs = 0;
      if (ns <= nd || serie || (antdr && !cs))
      {
        s++;
        p[s] = a[i];
        ns++;
        antdr = 0;
      }
      else
      {
        d--;
        p[d] = a[i];
        nd++;
        antdr = 1;
      }
      if (a[i] == a[i - 1])
        serie++;
      else
        serie = 0;
    }
    for (i = 0; i < n; i++)
      cout << p[i] << ' ';
  }
  return 0;
}
