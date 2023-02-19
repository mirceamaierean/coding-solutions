#include <fstream>
#include <stack>
#include <set>
#include <vector>
#include <algorithm>
#define NMAX 50001

using namespace std;

ifstream cin("retele.in");
ofstream cout("retele.out");

stack<int> st;
set<int> af[NMAX];
vector<int> g[NMAX];
vector<int> ig[NMAX];

char viz[NMAX];
int n, m, x, y, cnt;

void DFS1(int x)
{
  viz[x] = 1;

  for (vector<int>::iterator it = g[x].begin(); it != g[x].end(); ++it)
    if (viz[*it] == 0)
      DFS1(*it);

  st.push(x);
}

void DFS2(int x)
{
  af[cnt].insert(x);

  viz[x] = 0;

  for (vector<int>::iterator it = ig[x].begin(); it != ig[x].end(); ++it)
    if (viz[*it] == 1)
      DFS2(*it);
}

void solve()
{
  cin >> n >> m;

  for (int i = 1; i <= m; ++i)
  {
    cin >> x >> y;
    g[x].push_back(y);
    ig[y].push_back(x);
  }

  for (int i = 1; i <= n; ++i)
    if (viz[i] == 0)
      DFS1(i);

  while (!st.empty())
  {
    x = st.top();
    st.pop();
    if (viz[x] == 1)
    {
      cnt++;
      DFS2(x);
    }
  }

  cout << cnt << "\n";

  sort(af + 1, af + cnt + 1);

  for (int j = 1; j <= cnt; ++j)
  {
    cout << af[j].size();

    for (set<int>::iterator it = af[j].begin(); it != af[j].end(); ++it)
      cout << " " << *it;

    cout << "\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  solve();

  return 0;
}
