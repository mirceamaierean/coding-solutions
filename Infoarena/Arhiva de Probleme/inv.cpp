#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("inv.in");
ofstream fout("inv.out");

vector<pair<int, int>> v;

int n, aib[100001];
const int MOD = 9917;

void Update(int p, int val)
{
  for (int i = p; i <= n; i += i & -i)
  {
    aib[i] += val;
    if (aib[i] > MOD)
      aib[i] -= MOD;
  }
}

int64_t Query(int p)
{
  int64_t suma = 0;

  for (int i = p; i >= 1; i -= i & -i)
  {
    suma += aib[i];
    if (suma > MOD)
      suma -= MOD;
  }
  return suma;
}

int main()
{
  int a;
  fin >> n;

  v.resize(n);

  for (int i = 0; i < n; ++i)
  {
    fin >> a;
    v[i] = {a, i + 1};
  }
  sort(v.begin(), v.end(), greater<pair<int, int>>());

  int64_t cnt = 0;

  for (int i = 0; i < n; ++i)
  {
    cnt += Query(v[i].second);
    if (cnt > MOD)
      cnt -= MOD;
    Update(v[i].second, 1);
  }

  fout << cnt << "\n";

  return 0;
}