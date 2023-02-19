#include <iostream>
using namespace std;
int main()
{
    int n, i, S = 0;
    cin >> n;
    for (i = 1; i <= n / 2; i++)
        S = S + 2 * i * (n - i + 1);
    if (n % 2 == 1)
        S = S + (n + 1) / 2 * (n + 1) / 2;
    cout << "Rezultatul este " << S;
    return 0;
}
