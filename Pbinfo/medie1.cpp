#include <iostream>

using namespace std;
int a, b, c, m;
int main()
{
    cin >> a >> b >> c;
    m = (a + b + c) * 100 / 3;
    cout << m / 100 << "." << m % 100;
    if (m % 100 % 10 == 0)
        cout << 0;
    return 0;
}
