#include <fstream>
#include <algorithm>
#include <limits.h>
using namespace std;

ifstream cin("roata.in");
ofstream cout("roata.out");

int main()
{
  int n, p, v[100001], d[100001];
  unsigned long long suma = 0;
  cin >> n >> p;
  for (int i = 1; i <= n; ++i)
    d[i] = i;
  for (int i = 1; i <= p; ++i)
  {
    cin >> v[i];
    suma += v[i];
  }
  cout << suma << "\n";
  if (n < p)

    for (int k = n + 1; k <= p; ++k)
    {
      int pozmin = 1;
      for (int i = 2; i <= n; ++i)
        if (v[i] < v[pozmin])
          pozmin = i;
      cout << d[pozmin] << " ";
      if (v[pozmin] > 10000000)
        for (int i = 1; i <= n; ++i)
          v[i] -= 10000000;
      v[pozmin] += v[k];
      d[pozmin] = k;
    }
  else
    n = p;
  int pozmax = 1;
  for (int i = 2; i <= n; ++i)
    for (i = 2; i <= n; i++)
      if (v[i] >= v[pozmax])
        pozmax = i;
  for (int k = 1; k <= n; ++k)
  {
    int pozmin = 1;
    for (int i = 2; i <= n; ++i)
      if (v[i] < v[pozmin])
        pozmin = i;
    cout << d[pozmin] << " ";
    v[pozmin] += 100001;
  }
  cout << "\n"
       << pozmax << "\n";
  return 0;
}