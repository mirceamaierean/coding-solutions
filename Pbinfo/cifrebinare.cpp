#include <iostream>

using namespace std;

int main()
{
    int n, m, n1, m1, k = 0, l = 0;
    cin >> n >> m;
    n1 = n;
    m1 = m;
    while (n1)
    {
        if (n1 % 2 == 1)
            k++;
        n1 = n1 / 2;
    }
    while (m1)
    {
        if (m1 % 2 == 1)
            l++;
        m1 = m1 / 2;
    }
    if (k > l)
        cout << n;
    else
    {
        if (k == l)
        {
            if (n < m)
                cout << n;
            else
                cout << m;
        }
        else
            cout << m;
    }
    return 0;
}
