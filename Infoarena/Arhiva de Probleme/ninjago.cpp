#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
using namespace std;

ifstream fin("ninjago.in");
ofstream fout("ninjago.out");

const int NMAX = 31201;

struct p
{
  int x, cnte, val;
};

vector<p> v[NMAX];
vector<p> ve[NMAX];

bitset<NMAX> viz;

int BFS(int x)
{
  int cnt(0);
  queue<int> q;
  q.push(x);
  viz[x] = 1;
  while (!q.empty())
  {
    cnt++;
    int a = q.front();
    q.pop();
    for (auto i : v[a])
    {
      if (viz[i.x] == 0)
      {
        viz[i.x] = 1;
        q.push(i.x);
      }
    }
  }
  return cnt;
}

p ver(int x, string a)
{
  int cnte(0), val(0), fact = 1;
  for (int i = 0; i < 4; ++i)
  {
    if (a[i] == 'E')
      cnte++;
    else
      val += fact * (a[i] - 'A' + 1);
    fact *= 5;
  }
  return {x, cnte, val};
}

int c, n, m, x, y;
string a;

inline bool check(string s)
{
  return s[0] != 'E' && s[1] != 'E' && s[2] != 'E' && s[3] != 'E';
}

struct cmp
{
  bool operator()(const p &x, const p &y) const
  {
    if (x.cnte == y.cnte)
      return x.val > y.val;
    return x.cnte > y.cnte;
  }
};

int cnte, val_apm;

void APM()
{
  priority_queue<p, vector<p>, cmp> q;

  viz[1] = 1;

  for (auto i : v[1])
    q.push(i);

  for (auto i : ve[1])
    q.push(i);

  n--;

  viz[0] = 1;

  while (n)
  {
    p x;
    x.x = 0;
    while (viz[x.x])
    {
      x = q.top();
      q.pop();
    }
    n--;
    viz[x.x] = 1;
    cnte += x.cnte;
    val_apm += x.val;
    for (auto i : v[x.x])
      if (viz[i.x] == 0)
        q.push(i);
    for (auto i : ve[x.x])
      if (viz[i.x] == 0)
        q.push(i);
  }
}

int main()
{
  fin >> c >> n >> m;
  for (int i = 1; i <= m; ++i)
  {
    fin >> x >> y >> a;
    if (check(a))
    {
      v[x].push_back(ver(y, a));
      v[y].push_back(ver(x, a));
    }
    else
    {
      ve[x].push_back(ver(y, a));
      ve[y].push_back(ver(x, a));
    }
  }

  int cnt = BFS(1);

  if (c == 1)
  {
    fout << cnt << "\n";
    return 0;
  }

  cnt = 0;

  for (int i = 2; i <= n; ++i)
    if (viz[i] == 0)
    {
      BFS(i);
      cnt++;
    }

  viz.reset();

  APM();

  if (c == 2)
    fout << cnt << "\n"
         << cnte << "\n";
  else
    fout << val_apm << "\n";

  fout.close();
  return 0;
}
