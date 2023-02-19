#include <iostream>

using namespace std;
int main()
{
    int n, a, n10 = 0, n2 = 0, n5 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        while (a % 10 == 0)
        {
            ++n10;
            a /= 10;
        }
        while (a % 5 == 0)
        {
            ++n5;
            a /= 5;
        }
        while (a % 2 == 0)
        {
            ++n2;
            a /= 2;
        }
    }
    cout << n10 + min(n2, n5);
    return 0;
}
