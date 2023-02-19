#include <fstream>
#include <stack>
#include <vector>
#define NMAX 50005

using namespace std;

ifstream fin("sortaret.in");
ofstream fout("sortaret.out");

vector<int> g[NMAX];
stack<int> st;

int n, m, x, y;

bool vizitat[NMAX];

void DFS(int x)
{
    vizitat[x] = 1;
    for (size_t i = 0; i < g[x].size(); ++i)
        if (!vizitat[g[x][i]])
            DFS(g[x][i]);
    st.push(x);
}

void solve()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i)
        if (!vizitat[i])
            DFS(i);
    while (!st.empty())
    {
        fout << st.top() << " ";
        st.pop();
    }
}
int main()
{
    solve();
    return 0;
}
