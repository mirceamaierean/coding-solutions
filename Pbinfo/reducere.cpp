#include <iostream>

using namespace std;

int main()
{
    int t, n, m, a[1001], b[1001];
    cin >> t;
    for (int e = 1; e <= t; ++e)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; ++i)
            cin >> b[i];
        int i, k = 1, suma = 0;
        bool ok = true;
        for (i = 1; i <= n; ++i)
        {
            suma += a[i];
            if (suma == b[k])
            {
                suma = 0;
                ++k;
            }
            else if (suma > b[k] || k > m || (i == n && suma < b[k]))
            {
                ok = false;
                break;
            }
        }
        if (ok == true && k == m + 1 && i > n)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
