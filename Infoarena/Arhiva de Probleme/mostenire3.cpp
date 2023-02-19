#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

ifstream fin("mostenire3.in");
ofstream fout("mostenire3.out");

typedef pair<int, int> p;

int n, k, s;
vector<int> v;

vector<p> sol;
vector<p> a;

map<p, int> m;

bool check(int t)
{
  sol.clear();
  int s_crt = 0;
  for (int i = 0; i < n; ++i)
  {
    s_crt += v[i];
    if (s_crt >= t)
    {
      sol.push_back({s_crt, i + 1});
      s_crt = 0;
    }
  }
  return sol.size() >= k;
}

int b_search()
{
  int st = 1, dr = s, r = -1;
  while (st <= dr)
  {
    int mid = ((st + dr) >> 1);
    if (check(mid))
    {
      if (sol.size() == k)
        r = mid;
      st = mid + 1;
    }
    else
      dr = mid - 1;
  }
  return r;
}

int saci[103];

int main()
{
  fin >> n >> k;
  v.resize(n);

  for (int i = 0; i < n; ++i)
  {
    fin >> v[i];
    s += v[i];
  }
  int val = b_search();
  fout << val << "\n";

  check(val);

  for (int i = sol.back().second; i < n; ++i)
    sol.back().first += v[i];

  sol.back().second = n;

  a = sol;

  sort(a.begin(), a.end(), greater<p>());

  m[a[0]] = 1;

  for (int i = 1; i < k; ++i)
    m[a[i]] = i + 1;

  fout << m[sol[0]] << " " << sol[0].second << "\n";

  for (int i = 1; i < k; ++i)
    fout << m[sol[i]] << " " << sol[i].second - sol[i - 1].second << "\n";

  return 0;
}
