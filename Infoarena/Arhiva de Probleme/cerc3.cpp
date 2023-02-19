#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

ifstream fin("cerc3.in");
ofstream fout("cerc3.out");

typedef pair<double, double> p;

int n, maxi, tot;

double x, y, r;

map<double, vector<p>> m;

int main()
{
  fin >> n;
  for (int i = 1; i <= n; ++i)
  {
    fin >> x >> y >> r;
    double d = sqrt(x * x + y * y);
    m[y / x].push_back({d + r, d - r});
  }

  for (auto v : m)
  {
    sort(v.second.begin(), v.second.end());
    int cnt = 0;
    double l = -1000;
    for (auto i : v.second)
      if (i.second > l)
      {
        cnt++;
        l = i.first;
      }
    if (cnt > maxi)
    {
      maxi = cnt;
      tot = 1;
    }
    else if (cnt == maxi)
      tot++;
  }
  fout << m.size() << " " << maxi << " " << tot << "\n";

  return 0;
}