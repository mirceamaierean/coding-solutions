#include <fstream>
#include <algorithm>
#include <stack>
#include <vector>
#include <bitset>

std::ifstream fin("ciclueuler.in");
std::ofstream fout("ciclueuler.out");

const int NMAX = 1e5 + 2;

std::vector<std::pair<int, int>> g[NMAX];
std::bitset<5 * NMAX> used;

void euler()
{
    std::stack<int> st;
    st.push(1);
    std::vector<int> cycle;
    while (!st.empty())
    {
        int node = st.top();
        while (!g[node].empty() && used[g[node].back().second])
            g[node].pop_back();

        if (!g[node].empty())
        {
            int new_node = g[node].back().first;
            used[g[node].back().second] = 1;
            st.push(new_node);
        }

        else
        {
            st.pop();
            if (!st.empty())
                cycle.push_back(st.top());
        }
    }
    for (auto i : cycle)
        fout << i << " ";
    fout << "\n";
}

int n, x, y, m;

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y;
        g[x].push_back({y, i});
        g[y].push_back({x, i});
    }

    for (int i = 1; i <= n; ++i)
        if (!g[i].size() || g[i].size() & 1)
        {
            fout << "-1\n";
            return 0;
        }

    euler();

    fout.close();
    return 0;
}
