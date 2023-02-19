#include <fstream>
#include <stack>
#include <vector>
#define NMAX 100001

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

vector<int> g[NMAX];
vector<int> af[NMAX];
vector<int> ig[NMAX];

char viz[NMAX];

stack<int> st;

int n, m, x, y, cnt;

void DFS1(int x)
{
    viz[x] = 1;
    for (size_t i = 0; i < g[x].size(); ++i)
        if (viz[g[x][i]] == 0)
            DFS1(g[x][i]);
    st.push(x);
}

void DFS2(int x)
{
    af[cnt].push_back(x);
    viz[x] = 0;
    for (size_t i = 0; i < ig[x].size(); ++i)
        if (viz[ig[x][i]] == 1)
            DFS2(ig[x][i]);
}

void solve()
{
    fin >> n >> m;

    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
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

    fout << cnt << "\n";

    for (int j = 1; j <= cnt; ++j)
    {
        for (size_t i = 0; i < af[j].size(); ++i)
            fout << af[j][i] << " ";
        fout << "\n";
    }
}
int main()
{
    solve();
    return 0;
}
