#include <fstream>
#include <vector>
#include <bitset>

std::ifstream fin("nivele2.in");
std::ofstream fout("nivele2.out");

const int NMAX = 1e5 + 1;

std::vector<int> g[NMAX];
std::vector<int> sol[NMAX];
std::bitset<NMAX> used;

void DFS(int nod, int level)
{
  sol[level].push_back(nod);

  used[nod] = 1;

  for (auto i : g[nod])
    if (!used[i])
      DFS(i, level + 1);
}

int n, m, x, y;

int main()
{
  fin >> n;

  for (int i = 1; i < n; ++i)
  {
    fin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  DFS(1, 1);

  for (int i = 1; i <= NMAX && sol[i].size(); ++i)
  {
    fout << "nivelul " << i << ":";

    for (auto x : sol[i])
      fout << " " << x;

    fout << "\n";
  }

  fout.close();
  return 0;
}