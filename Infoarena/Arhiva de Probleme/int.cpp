#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("int.in");
ofstream fout("int.out");

typedef pair<int, int> p;

vector<p> v;

int n;

inline bool cmp(const p &a, const p &b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

p a;

int cnt, ind;

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> a.first >> a.second;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), cmp);

    cnt = 1;
    for (int i = 1; i < n; ++i)
        if (v[i].first >= v[ind].second)
        {
            cnt++;
            ind = i;
        }

    fout << cnt << "\n";

    fout.close();
    return 0;
}
