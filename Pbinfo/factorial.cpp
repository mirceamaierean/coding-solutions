#include <iostream>
using namespace std;

int main()
{
    unsigned long long i, n, fact = 1;
    cin >> n;
    for (i = 2; i <= n; ++i)
        fact *= i;
    cout << fact;
    return 0;
}
