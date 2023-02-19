#include <iostream>
#include <algorithm>
using namespace std;

int a, b;

int main()
{
    cin >> a >> b;
    int cmmdc = __gcd(a, b);
    if (cmmdc > 1)
        cout << "NO";
    cout << "PIE";
    return 0;
}