#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct numar
{
    int nr, sumcif;
};
numar v[101];
inline bool cmp(numar a, numar b)
{
    if (a.sumcif == b.sumcif)
        return a.sumcif > b.sumcif;
    else
        return a.sumcif < b.sumcif;
}
ifstream cin("sortcif.in");
ofstream cout("sortcif.out");
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i].nr;
        int g = v[i].nr;
        while (g)
        {
            v[i].sumcif += g % 10;
            g /= 10;
        }
    }
    sort(v + 1, v + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        cout << v[i].nr << " ";
    return 0;
}
