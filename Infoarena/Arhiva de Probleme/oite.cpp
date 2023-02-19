#include <fstream>
#include <vector>
using namespace std;

ifstream fin("oite.in");
ofstream fout("oite.out");

const int MOD = 1e5 + 7;

int n, cnt, l;

vector<pair<int, int>> h[MOD + 5];

void update(int val)
{
    if (val > l)
        return;
    int s = val % MOD;
    for (size_t i = 0; i < h[s].size(); ++i)
    {
        if (h[s][i].first == val)
        {
            h[s][i].second++;
            return;
        }
    }
    h[s].push_back({val, 1});
}
int query(int val)
{
    int s = val % MOD;
    if (val < 0)
        return 0;
    for (size_t i = 0; i < h[s].size(); ++i)
        if (h[s][i].first == val)
            return h[s][i].second;
    return 0;
}

int main()
{
    fin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        fin >> v[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
            cnt += query(l - v[i] - v[j]);
        for (int j = 0; j < i; ++j)
            update(v[i] + v[j]);
    }

    fout << cnt << "\n";
    return 0;
}
