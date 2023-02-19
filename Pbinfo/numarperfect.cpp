#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool perfect(int n)
{
    int j = sqrt(n), suma = 1;
    if (j * j == n)
    {
        suma += j;
        --j;
    }
    for (int i = 2; i <= j; ++i)
    {
        if (n % i == 0)
            suma += i + n / i;
        if (suma > n)
            return 0;
    }
    if (suma == n)
        return 1;
    return 0;
}
int main()
{
    int n;
    cin >> n;
    cout << n << " ";
    if (perfect(n) == 0)
        cout << "nu ";
    cout << "este perfect";
    return 0;
}
