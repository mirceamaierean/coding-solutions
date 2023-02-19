#include <fstream>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

ifstream fin("freakadebunic.in");
ofstream fout("freakadebunic.out");

const int NMAX = 1e5 + 3;

vector<int> g[NMAX];
bitset<NMAX> afis;
bitset<NMAX> viz;

int n, k, a, turn[NMAX];

void DFS(int x)
{
  viz[x] = 1;
  for (size_t i = 0; i < g[x].size(); ++i)
    if (viz[g[x][i]] == 0)
    {
      DFS(g[x][i]);
      turn[x] += turn[g[x][i]];
    }
  if (turn[x] >= 2)
  {
    afis[x] = true;
    turn[x] = 1;
  }
}

int main()
{
  fin >> n >> k;
  while (k--)
  {
    fin >> a;
    turn[a] = 1;
  }

  for (int i = 1; i <= n; ++i)
  {
    fin >> a >> k;
    g[a].push_back(k);
    g[k].push_back(a);
  }

  DFS(1);

  fout << afis.count() << "\n";

  for (int i = 1; i <= n; ++i)
    if (afis[i] == 1)
      fout << i << " ";

  return 0;
}
