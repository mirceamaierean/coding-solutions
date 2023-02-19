#include <fstream>
#include <vector>
#include <set>

using namespace std;

ifstream fin("euro2.in");
ofstream fout("euro2.out");

vector<double> v;
vector<int> d_c;
vector<int> d_d;
int n, maxi;

int main()
{
  fin >> n;

  v.resize(n);
  d_c.resize(n, 0);
  d_d.resize(n, 0);

  for (int i = 0; i < n; ++i)
    fin >> v[i];

  set<double> lis;

  for (int i = 0; i < n; ++i)
  {
    auto crt = lis.upper_bound(v[i]);
    if (crt == lis.end())
      lis.insert(v[i]);
    else
    {
      lis.erase(crt);
      lis.insert(v[i]);
    }

    d_c[i] = lis.size();
  }

  lis.clear();

  for (int i = n - 1; i >= 0; --i)
  {
    auto crt = lis.upper_bound(v[i]);
    if (crt == lis.end())
      lis.insert(v[i]);
    else
    {
      lis.erase(crt);
      lis.insert(v[i]);
    }

    d_d[i] = lis.size();

    if (d_c[i] >= 2 && d_d[i] >= 2 && d_c[i] + d_d[i] - 1 > maxi)
      maxi = d_c[i] + d_d[i] - 1;
  }

  fout << maxi << "\n";

  return 0;
}