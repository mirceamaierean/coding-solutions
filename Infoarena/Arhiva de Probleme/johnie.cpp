#include <fstream>
#include <vector>
#include <bitset>
#include <stack>

std::ifstream fin("johnie.in");
std::ofstream fout("johnie.out");

const int NMAX = 5 * 1e4 + 1;
const int MMAX = 2e5 + 1;

std::vector<std::pair<int, int>> g[NMAX];
std::vector<std::vector<int>> sol;
std::bitset<MMAX> used;

void euler(int start)
{
    std::stack<int> st;
    st.push(start);
    while (!st.empty())
    {
        int crt = st.top();
        while (g[crt].size() && used[g[crt].back().second])
            g[crt].pop_back();
        if (!g[crt].empty())
        {
            st.push(g[crt].back().first);
            used[g[crt].back().second] = 1;
        }
        else
        {
            if (crt)
                sol.back().push_back(crt);
            else if (st.size() > 1)
                sol.push_back(std::vector<int>());
            st.pop();
        }
    }
}

int n, m, x, y;

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
        if (g[i].size() & 1)
        {
            g[i].push_back({0, ++m});
            g[0].push_back({i, m});
        }

    euler(0);

    for (int i = 1; i <= n; ++i)
        if (g[i].size())
            euler(i);

    fout << sol.size() << "\n";

    for (auto v : sol)
    {
        fout << v.size() << " ";
        for (auto i : v)
            fout << i << ' ';
        fout << "\n";
    }

    fout.close();
    return 0;
}
