#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#define x first
#define y second
using namespace std;

ifstream fin("mission.in");
ofstream fout("mission.out");

typedef pair<long long, long long> point;

vector<point> v;

inline long long det(point a, point b, point c)
{
  return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

inline bool cmp(point a, point b)
{
  return det(v[0], a, b) < 0;
}

map<point, int> m;

const int NMAX = 1003;

int st[NMAX], n, mini;

int main()
{
  fin >> n;
  v.resize(n);
  for (int i = 0; i < n; ++i)
  {
    fin >> v[i].x >> v[i].y;
    if (v[mini] > v[i])
      mini = i;
    m[v[i]] = i;
  }
  swap(v[mini], v[0]);
  sort(v.begin() + 1, v.end(), cmp);
  for (int i = 0; i < n; ++i)
    st[i] = m[v[i]];

  int p = 0;

  for (int i = 0; i < n; ++i)
  {
    if (m[v[i]] == 0)
      p = i + 1;
    if (p)
      fout << m[v[i]] << " ";
  }

  --p;

  for (int i = 0; i < p; ++i)
    fout << m[v[i]] << " ";
  return 0;
}