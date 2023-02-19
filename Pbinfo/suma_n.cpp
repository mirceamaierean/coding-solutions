#include <iostream>
using namespace std;
int main()
{
    int n, a, suma = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        suma += a;
    }
    cout << suma;
    return 0;
}
