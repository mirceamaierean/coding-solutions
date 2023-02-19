#include <fstream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
ifstream cin("sumtri1.in");
ofstream cout("sumtri1.out");
int a[101][101], b[101][101], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
        {
            cin >> a[i][j];
            if (min(b[i - 1][j - 1], b[i - 1][j]))
                b[i][j] = a[i][j] + min(b[i - 1][j - 1], b[i - 1][j]);
            else
                b[i][j] = a[i][j] + max(b[i - 1][j - 1], b[i - 1][j]);
        }
    int poz = 0, min = INT_MAX, val;
    for (int i = 1; i <= n; ++i)
        if (b[n][i] < min)
        {
            min = b[n][i];
            poz = i;
        }

    cout << min << "\n";
    vector<int> v;
    while (n)
    {
        v.push_back(a[n][poz]);
        --n;
        if (poz > n || (b[n][poz - 1] < b[n][poz] && poz > 1))
            --poz;
    }
    for (int i = v.size() - 1; i >= 0; --i)
        cout << v[i] << " ";
    return 0;
}
