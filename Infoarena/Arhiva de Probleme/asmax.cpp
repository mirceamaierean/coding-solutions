#include <fstream>
#include <vector>
#include <bitset>

using namespace std;

const int NMAX = 16e3 + 1;

vector<int> g[NMAX];
bitset<NMAX> used;

int a[NMAX], n, x, y;

void solve(int node)
{
    used[node] = 1;
    for (auto i : g[node])
        if (used[i] == 0)
        {
            solve(i);
            a[node] += a[i];
        }
    if (a[node] < 0)
        a[node] = 0;
}

ifstream fin("asmax.in");
ofstream fout("asmax.out");

int main()
{
    int maxi = -10002;
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
        if (a[i] > maxi)
            maxi = a[i];
    }
    for (int i = 1; i < n; ++i)
    {
        fin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    solve(1);

    for (int i = 1; i <= n; ++i)
        if (a[i] && a[i] > maxi)
            maxi = a[i];

    fout << maxi << '\n';

    return 0;
}
