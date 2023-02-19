#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

ifstream fin("petrica.in");
ofstream fout("petrica.out");

const int NMAX = 203;

typedef pair<int, int> p;

vector<int> g[NMAX];
vector<p> v;
vector<int> noduri;

int x, y, n, s[NMAX], level[NMAX];

bitset<NMAX> viz;

bitset<NMAX> s_arb[NMAX];

int DFS(int nod)
{
    viz[nod] = 1;
    for (auto i : noduri)
    {
        s_arb[nod][i] = 1;
        s_arb[i][nod] = 1;
    }
    noduri.push_back(nod);
    for (auto i : g[nod])
    {
        if (viz[i] == 0)
        {
            level[i] = level[nod] + 1;
            s[nod] += DFS(i);
        }
    }
    noduri.pop_back();
    return s[nod];
}

int l_max, l_min;

inline bool cmp(p a, p b)
{
    return level[a.second] < level[b.second];
}

int main()
{
    fin >> n;

    for (int i = 1; i <= n; ++i)
        fin >> s[i];

    for (int i = 1; i < n; ++i)
    {
        fin >> x >> y;
        v.push_back({x, y});
        g[x].push_back(y);
        g[y].push_back(x);
    }

    DFS(1);

    int m = n - 1;

    for (int i = 0; i < m; ++i)
        if (level[v[i].second] < level[v[i].first])
            v[i] = {v[i].second, v[i].first};

    sort(v.begin(), v.end(), cmp);

    int mini = 0x3f3f3f;

    int tot = s[1];

    for (int i = 0; i < m; ++i)
    {
        for (int j = i + 1; j < m; ++j)
        {
            for (int k = j + 1; k < m; ++k)
            {
                int s2 = s[v[j].second], s3 = s[v[k].second], s1 = s[v[i].second];
                if (s_arb[v[i].second][v[j].second])
                {
                    s1 -= s2;
                    if (s_arb[v[j].second][v[k].second])
                        s2 -= s3;
                    else if (s_arb[v[i].second][v[k].second])
                        s1 -= s3;
                }
                else
                {
                    if (s_arb[v[j].second][v[k].second])
                        s2 -= s3;
                    else if (s_arb[v[i].second][v[k].second])
                        s1 -= s3;
                }

                int s4 = tot - (s1 + s2 + s3);

                l_max = max({s1, s2, s3, s4});
                l_min = min({s1, s2, s3, s4});
                mini = min(mini, l_max - l_min);
            }
        }
    }
    fout << mini << "\n";
    fout.close();
    return 0;
}