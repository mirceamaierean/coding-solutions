#include <iostream>

using namespace std;

unsigned long long n, suma, ant = 1;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        ant *= i;
        suma += ant;
    }
    cout << "Rezultatul este " << suma << '\n';
    return 0;
}