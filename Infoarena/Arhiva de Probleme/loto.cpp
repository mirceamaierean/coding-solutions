#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

ifstream fin("loto.in");
ofstream fout("loto.out");

struct tripla
{
    int first, second, third;
};

vector<tripla> v;
vector<int> f;
int n, s, a;

inline bool cmp(tripla a, tripla b)
{
    if (a.first == b.first)
    {
        if (a.second == b.second)
            return a.third < b.third;
        return a.second < b.second;
    }
    return a.first < b.first;
}

inline int binary_search(int val)
{
    int st = 0, dr = v.size() - 1, mij;
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        if (v[mij].first == val)
            return mij;
        if (v[mij].first < val)
            st = mij + 1;
        else
            dr = mij - 1;
    }
    return -1;
}

int main()
{
    fin >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        fin >> a;
        f.push_back(a);
        for (int j = 0; j < f.size(); ++j)
            for (int k = 0; k <= j; ++k)
                v.push_back({f[j] + f[k] + a, f[j], f[k]});
    }
    sort(v.begin(), v.end(), cmp);

    bool ok = false;
    int i1, i2;

    for (size_t i = 0; i < v.size(); ++i)
    {
        int val = binary_search(s - v[i].first);
        if (val != -1)
        {
            ok = true;
            i1 = i;
            i2 = val;
        }
    }
    if (ok == false)
        fout << "-1";
    else
    {
        multiset<int> s;
        s.insert(v[i1].second);
        s.insert(v[i1].third);
        s.insert(v[i1].first - v[i1].second - v[i1].third);
        s.insert(v[i2].second);
        s.insert(v[i2].third);
        s.insert(v[i2].first - v[i2].second - v[i2].third);
        set<int>::iterator it;
        for (it = s.begin(); it != s.end(); ++it)
            fout << *it << " ";
    }
    return 0;
}