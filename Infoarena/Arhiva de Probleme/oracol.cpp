#include <fstream>
#include <queue>
#include <bitset>
#include <vector>
using namespace std;

ifstream fin("oracol.in");
ofstream fout("oracol.out");

const int NMAX = 1e3 + 1;

typedef pair<int, int> p;

priority_queue<p, vector<p>, greater<p>> q;

int n, x;

vector<p> g[NMAX];

bitset<NMAX> used;

int Prim()
{
  q.push({0, 0});
  int sum = 0;
  ++n;
  while (n--)
  {
    p crt;
    do
    {
      crt = q.top();
      q.pop();
    } while (!q.empty() && used[crt.second] == 1);

    used[crt.second] = 1;

    sum += crt.first;

    for (auto x : g[crt.second])
      if (used[x.first] == 0)
        q.push({x.second, x.first});
  }
  return sum;
}

int main()
{
  fin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j <= n; ++j)
    {
      fin >> x;
      g[i].push_back({j, x});
      g[j].push_back({i, x});
    }
  fout << Prim() << '\n';
  return 0;
}
