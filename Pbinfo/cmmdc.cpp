#include <iostream>
#include <algorithm>
using namespace std;

int a, b;

int main()
{
    cin >> a >> b;
    if (a == 0 && b == 0)
        cout << -1 << "\n";
    else
        cout << __gcd(a, b) << "\n";
    return 0;
}