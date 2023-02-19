#include <iostream>

using namespace std;

int suma, n;

int main()
{
    cin >> n;
    while (n != 0)
    {
        suma += n;
        cin >> n;
    }
    cout << suma;
    return 0;
}