#include <fstream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

ifstream fin("plimbare.in");
ofstream fout("plimbare.out");

const int NMAX = 104;

vector<int> g[NMAX];
vector<int> t[NMAX];
deque<int> af;
deque<int> cr;
stack<int> st;

char e[NMAX][NMAX];

int n, m;
char viz[NMAX];

void DFS(int x)
{
    viz[x] = 1;
    for (size_t i = 0; i < g[x].size(); ++i)
        if (viz[g[x][i]] == 0)
            DFS(g[x][i]);
    st.push(x);
}

void DFS2(int x)
{
    viz[x] = 2;
    for (size_t i = 0; i < t[x].size(); ++i)
        if (viz[t[x][i]] == 1)
            DFS2(t[x][i]);
    cr.push_back(x);
}

void solve()
{
    int x, y;
    size_t max = 0;
    fin >> n;
    for (int i = 1; i <= n * (n - 1) / 2; ++i)
    {
        fin >> x >> y;
        g[x].push_back(y);
        t[y].push_back(x);
        e[x][y] = 1;
    }

    for (int i = 1; i <= n; ++i)
        if (viz[i] == 0)
            DFS(i);

    while (!st.empty())
    {
        cr.clear();
        x = st.top();
        st.pop();
        if (viz[x] == 1)
            DFS2(x);
        if (cr.size() > max)
        {
            max = cr.size();
            af = cr;
        }
    }

    fout << max << "\n";

    --max;

    bool ok = false;
    do
    {
        ok = true;
        for (int i = 0; i < max; ++i)
            if (e[af[i]][af[i + 1]] == 0)
            {
                ok = false;
                swap(af[i], af[i + 1]);
            }
        if (e[af[max]][af[0]] == 0)
        {
            ok = false;
            swap(af[max], af[0]);
        }
    } while (ok == false);

    for (size_t i = 0; i < af.size(); ++i)
        fout << af[i] << " ";
}
int main()
{
    solve();
    return 0;
}
