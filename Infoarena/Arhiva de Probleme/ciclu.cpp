#include <fstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <vector>

std::ifstream fin("ciclu.in");
std::ofstream fout("ciclu.out");

const int NMAX = 1002;
const int oo = 2e9;

typedef std::pair<int, int> p;
std::vector<p> g[NMAX];

int n, m;

bool BF(int val)
{
    std::vector<long long> d(n + 1, oo);
    std::vector<int> used(n + 1, 0);

    d[0] = 0;

    std::queue<int> q;

    q.push(0);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto i : g[x])
        {
            long long cost = i.second - val;

            if (d[x] + cost < d[i.first])
            {
                d[i.first] = d[x] + cost;
                q.push(i.first);
                ++used[i.first];
                if (used[i.first] >= n)
                    return 1;
            }
        }
    }
    return 0;
}

int x, y, c, st, dr;

int main()
{
    fin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        fin >> x >> y >> c;
        c *= 1000;
        if (c > dr)
            dr = c;
        g[x].push_back({y, c});
    }

    for (int i = 1; i <= n; ++i)
        g[0].push_back({i, 0});

    st = 1;

    int res = dr;

    while (st <= dr)
    {
        int mid = (st + dr) / 2;
        if (BF(mid))
        {
            if (mid < res)
                res = mid;
            dr = mid - 1;
        }
        else
            st = mid + 1;
    }

    double val = double(res) / 1000;

    fout << std::fixed << std::setprecision(2) << val << '\n';
    fout.close();
    return 0;
}
