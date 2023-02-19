#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        if (isprime(a) == 0)
            cout << a << " ";
    }
    return 0;
}
