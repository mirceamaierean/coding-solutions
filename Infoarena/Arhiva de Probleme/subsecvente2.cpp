#include <fstream>
#include <string.h>
#include <algorithm>
std::ifstream fin("subsecvente2.in");
std::ofstream fout("subsecvente2.out");

const int NMAX = 5 * 1e4 + 2;

struct node
{
  int cnt;
  node *sons[2];
  node()
  {
    memset(sons, 0, sizeof sons);
    cnt = 0;
  }
};

node *root = new node();

int n;
char s[NMAX];

inline void insert(node *root, char *s, int index, int level)
{
  if (root->cnt < index - 1 || level >= 61)
    return;
  root->cnt = index;
  if (!*s)
    return;
  int son = *s - 'a';
  if (!root->sons[son])
    root->sons[son] = new node();
  insert(root->sons[son], s + 1, index, level + 1);
}

inline int DFS(node *root)
{
  int r(0);
  if (root->sons[0] && root->sons[0]->cnt == n)
    r = 1 + DFS(root->sons[0]);
  if (root->sons[1] && root->sons[1]->cnt == n)
    r = std::max(r, 1 + DFS(root->sons[1]));
  return r;
}

int main()
{
  fin >> n;
  for (int i = 1; i <= n; ++i)
  {
    fin >> s;
    for (int j = 0; s[j]; ++j)
      insert(root, s + j, i, 0);
  }

  fout << DFS(root);

  fout.close();
  return 0;
}
