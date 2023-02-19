#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("reinvent.in");
ofstream fout("reinvent.out");

const int NMAX = 1e5 + 2;

vector<int> v[NMAX];

int n, m, x, a, b;

struct viz
{
  int dad, dist;
};

viz ok[NMAX];

queue<int> q;

int solve()
{
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (auto i : v[x])
    {
      if (ok[i].dad == 0)
      {
        ok[i].dad = ok[x].dad;
        ok[i].dist = ok[x].dist + 1;
        q.push(i);
      }
      else if (ok[i].dad != ok[x].dad)
        return ok[i].dist + ok[x].dist + 1;
    }
  }
}

int main()
{
  fin >> n >> m >> x;
  for (int i = 1; i <= m; ++i)
  {
    fin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= x; ++i)
  {
    fin >> a;
    ok[a].dad = a;
    q.push(a);
  }

  fout << solve() << "\n";

  fout.close();
  return 0;
}