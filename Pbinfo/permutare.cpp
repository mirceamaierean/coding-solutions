#include <iostream>
using namespace std;
int main()
{
    int sum = 0, n, a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        sum += a;
    }
    if (sum == n * (n + 1) / 2)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
