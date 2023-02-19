#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }

    for (int i = 1; i <= b; ++i)
        if (b % i == 0)
            cout << i << " ";
    return 0;
}