#include <iostream>
using namespace std;

int main()
{
    long long n, a, b;
    cin >> n;
    a = n + 1;
    b = 2 * n + 1;
    if (n % 2 == 0)
        n /= 2;
    else
        a /= 2;
    if (n % 3 == 0)
        n /= 3;
    else if (a % 3 == 0)
        a /= 3;
    else
        b /= 3;
    cout << "Rezultatul este " << n * a * b;
    return 0;
}