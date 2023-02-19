#include <iostream>

using namespace std;

int main()
{
    int n, k = 1;
    cin >> n;
    while (n >= 10)
    {
        k++;
        n = n / 10;
    }
    cout << k;
    return 0;
}
