#include <iostream>

using namespace std;

int main()
{
    int n, o = 0, c;
    cin >> n;
    while (n != 0)
    {
        c = n % 10;
        o = o * 10 + c;
        n = n / 10;
    }
    cout << o;
    return 0;
}