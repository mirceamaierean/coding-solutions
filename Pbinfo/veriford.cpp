#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int k, n, a;
    cin >> k;
    for (int i = 1; i <= k; ++i)
    {
        int val = INT_MIN;
        bool ok = true;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a;
            if (a < val)
                ok = false;
            val = a;
        }
        if (ok == true)
            cout << "1 ";
        else
            cout << "0 ";
    }
    return 0;
}
