#include <fstream>
#include <stdlib.h>
#define N 100010
int v[N];

int bsearch0(int p, int u, int key)
{
    int m;

    while (p <= u)
    {
        m = (p + u) / 2;
        if (v[m] <= key)
            p = m + 1;
        else
            u = m - 1;
    }
    m = (p + u) / 2;
    if (v[m] > key)
        m--;
    if (v[m] == key)
        return m;
    return -1;
}

int bsearch1(int p, int u, int key)
{
    int m, n = u;
    while (p < u)
    {
        m = (p + u) / 2;
        if (v[m] <= key)
            p = m + 1;
        else
            u = m;
    }
    m = (p + u) / 2;
    if (v[m] > key)
        --m;
    return m;
}

int bsearch2(int p, int u, int key)
{
    int m;
    while (p < u)
    {
        m = (p + u) / 2;
        if (v[m] < key)
            p = m + 1;
        else
            u = m;
    }

    m = (p + u) / 2;
    if (v[m] < key)
        ++m;
    return m;
}
using namespace std;
ifstream cin("cautbin.in");
ofstream cout("cautbin.out");
int main()
{
    int i, n, m, tip, val;
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> v[i];
    cin >> m;
    while (m--)
    {
        cin >> tip >> val;
        if (tip == 0)
            cout << bsearch0(1, n, val) << "\n";
        else if (tip == 1)
            cout << bsearch1(1, n, val) << "\n";
        else if (tip == 2)
            cout << bsearch2(1, n, val) << "\n";
    }
    return 0;
}
