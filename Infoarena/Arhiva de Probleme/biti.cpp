#include <fstream>
#include <vector>
#include <deque>
#include <bitset>

std::ifstream fin("biti.in");
std::ofstream fout("biti.out");

int n, k;

const int NMAX = 1024 * 1025;

std::bitset<NMAX> used;
std::vector<int> sol;

void eul(int node)
{
  int _node = node;
  if (node >= k)
    node -= k;
  node <<= 1;
  used[_node] = true;
  if (!used[node])
    eul(node);
  if (!used[node + 1])
    eul(node + 1);
  sol.push_back(_node);
}

int main()
{
  fin >> n;
  k = (1 << (n - 1));

  fout << (k << 1) + n - 1 << "\n";

  for (int i = 1; i <= n; ++i)
    fout << '0';

  sol.reserve((k << 1));

  eul(0);

  sol.pop_back();

  for (int i = sol.size() - 1; i >= 0; --i)
    fout << (sol[i] & 1);

  fout << "\n";
  return 0;
}