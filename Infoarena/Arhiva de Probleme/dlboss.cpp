#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("dlboss.in");
ofstream fout("dlboss.out");

struct boss
{
  int t, c, ind;
};

priority_queue<int> q;

const int NMAX = 1e5 + 2;

vector<boss> v;

int query[NMAX];

int n, t, s_crt;

inline bool cmp(boss a, boss b)
{
  if (a.c == b.c)
    return a.t > b.t;
  return a.c > b.c;
}

int main()
{
  fin >> n >> t;
  v.resize(n);

  for (int i = 0; i < n; ++i)
  {
    fin >> v[i].t >> v[i].c;
    v[i].ind = i;
  }

  sort(v.begin(), v.end(), cmp);

  for (int i = 0; i < n; ++i)
  {
    query[v[i].ind] = q.size();
    if (i < n - 1 && v[i].c == v[i + 1].c)
      continue;
    q.push(v[i].t);
    s_crt += v[i].t;
    while (s_crt > t && !q.empty())
    {
      s_crt -= q.top();
      q.pop();
    }
  }

  for (int i = 0; i < n; ++i)
    fout << query[i] << "\n";

  return 0;
}
