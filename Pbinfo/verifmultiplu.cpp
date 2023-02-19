#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, cm;
    cin >> n;
    cin >> a;
    cm = a;
    for (int i = 1; i < n; ++i)
    {
        cin >> a;
        cm = __gcd(cm, a);
    }
    if (cm == a)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
