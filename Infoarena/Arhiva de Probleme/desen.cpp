#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

ifstream fin("desen.in");
ofstream fout("desen.out");

const int NMAX = 1004;
const int oo = 0x3f3f3f;
typedef pair<int, double> p;

struct point
{
  int x, y;
  double c;
};

inline double compute_distance(p a, p b)
{
  double x = a.first - b.first, y = a.second - b.second;
  return sqrt(x * x + y * y);
}

int n, t[NMAX];

vector<p> v;
vector<point> m;

inline bool cmp(point a, point b)
{
  return a.c < b.c;
}

int union_find(int x)
{
  while (t[x] != x)
    x = t[x];
  return x;
}

double apm(int k)
{
  double cost = 0;
  int cnt = 0;
  vector<point> aux;

  for (int i = 0; cnt < k - 1; ++i)
  {
    int a = union_find(m[i].x), b = union_find(m[i].y);
    if (a != b)
    {
      ++cnt;
      t[a] = b;
      aux.push_back(m[i]);
      cost += m[i].c;
    }
  }
  m = aux;
  return cost;
}

int main()
{
  point a;
  fin >> n;
  v.resize(n + 1);
  for (int i = 1; i <= n; ++i)
  {
    fin >> v[i].first >> v[i].second;
    t[i] = i;
    for (int j = 1; j < i; ++j)
    {
      t[j] = j;
      a.x = i;
      a.y = j;
      a.c = compute_distance(v[i], v[j]);
      m.push_back(a);
    }
    sort(m.begin(), m.end(), cmp);
    fout << fixed << setprecision(6) << apm(i) << "\n";
  }
  return 0;
}