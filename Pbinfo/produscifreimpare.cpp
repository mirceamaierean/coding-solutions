#include <iostream>

using namespace std;

int main()
{
    int n, p = 1, k = 0;
    cin >> n;
    while (n)
    {
        if (n % 2 == 1)
            p = p * (n % 10);
        if (n % 10 == 1)
            k++;
        n = n / 10;
    }
    if (p == 1 && k == 0)
        cout << -1;
    else
        cout << p;
    return 0;
}
