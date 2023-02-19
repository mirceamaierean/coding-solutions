#include <fstream>
#include <vector>
#include <bitset>
#include <string>
using namespace std;

ifstream fin("senat.in");
ofstream fout("senat.out");

int n, m, cnt, r[103], l[103];

string a;

vector<int> g[103];

bitset<103> used;

bool pair_up(int node)
{
    if (used[node])
        return 0;

    used[node] = 1;

    for (auto i : g[node])
    {
        if (!l[i])
        {
            r[node] = i;
            l[i] = node;
            return 1;
        }
    }

    for (auto i : g[node])
    {
        if (pair_up(l[i]))
        {
            r[node] = i;
            l[i] = node;
            return 1;
        }
    }
    return 0;
}

int main()
{
    fin >> n >> m;
    fin.get();
    for (int i = 1; i <= m; ++i)
    {
        getline(fin, a);

        for (size_t j = 0; j < a.size(); ++j)
        {
            int nr = 0;
            while (j < a.size() && isdigit(a[j]))
            {
                nr = nr * 10 + (a[j] - '0');
                ++j;
            }
            g[i].push_back(nr);
        }
    }

    bool ok = true;
    while (ok)
    {
        ok = false;
        used.reset();
        for (int i = 1; i <= m; ++i)
            if (!r[i] && pair_up(i))
            {
                cnt++;
                ok = true;
            }
    }

    if (cnt == m)
    {
        for (int i = 1; i <= m; ++i)
            fout << r[i] << "\n";
    }
    else
        fout << "0\n";

    fout.close();
    return 0;
}
