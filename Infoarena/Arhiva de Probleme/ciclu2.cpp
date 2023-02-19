#include <fstream>
#include <bitset>
#include <vector>

std::ifstream fin("ciclu2.in");
std::ofstream fout("ciclu2.out");

const int NMAX = 205;
const int MMAX = 355;

typedef std::pair<int, int> p;

std::bitset<MMAX> used;
std::vector<p> g[NMAX];

int requiredNode;

bool ok;

void DFS(int node, int length, int edge)
{
  used[edge] = 1;

  for (auto x : g[node])
  {
    if (used[x.second] == 0)
    {
      if (length == 1)
      {
        if (x.first == requiredNode)
        {
          ok = 1;
          return;
        }
      }
      else
      {
        DFS(x.first, length - 1, x.second);
        if (ok)
          return;
      }
    }
  }

  used[edge] = 0;
}

int v, e, q, x, y;

int main()
{
  fin >> v >> e;

  for (int i = 1; i <= e; ++i)
  {
    fin >> x >> y;
    g[x].push_back({y, i});
    g[y].push_back({x, i});
  }

  fin >> q;

  while (q--)
  {
    used.reset();
    fin >> requiredNode >> y;
    ok = 0;
    DFS(requiredNode, y, 0);
    fout << ok << "\n";
  }

  fout.close();
  return 0;
}
