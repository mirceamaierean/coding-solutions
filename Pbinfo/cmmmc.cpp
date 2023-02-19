#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long a, b;

int main()
{
    cin >> a >> b;
    unsigned long long prod = a * b;
    b = __gcd(a, b);
    cout << prod / b << "\n";
    return 0;
}