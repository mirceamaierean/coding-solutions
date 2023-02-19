#include <iostream>
using namespace std;
int main()
{
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        cout << a << " ";
        if (a % 2 == 0)
            cout << 2 * a << " ";
    }
    return 0;
}