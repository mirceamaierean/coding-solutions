#include <fstream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

ifstream fin("biconex.in");
ofstream fout("biconex.out");

const int NMAX = 1e5 + 2;
vector <int> v[NMAX];
stack <int> st;
vector <deque <int> > compBic;

int n, m, x, y, nivel[NMAX], nma[NMAX];

void DFS(int x, int dad)
{
  nivel[x] = nivel[dad] + 1;
  nma[x] = nivel[x];
  st.push(x);
  for (auto y : v[x])
  {
    if (y == dad)
      continue;
    if (nivel[y])
      nma[x] = min(nma[x], nivel[y]);
    else
    {
      DFS(y, x);
      nma[x] = min(nma[x], nma[y]);
      if (nma[y] >= nivel[x])
      {
        deque <int> comp;
        while (st.top() != y)
        {
          comp.push_front(st.top());
          st.pop();
        }
        comp.push_front(st.top());
        comp.push_front(x);
        compBic.push_back(comp);
        st.pop();
      }
    }
  }
}

int main()
{
  fin >> n >> m;
  for (int i = 1; i <= m; ++i)
  {
    fin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  for (int i = 1; i <= n; ++i)
    if (!nivel[i])
      DFS(i, 0);

  fout << compBic.size() << '\n';

  for (auto comp : compBic)
  {
    for (auto nod : comp)
      fout << nod << ' ';
    fout << '\n';
  }

  return 0;
}
