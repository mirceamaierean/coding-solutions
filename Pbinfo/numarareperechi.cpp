#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int cnt, n, ant;

int main()
{
    cin >> ant >> n;
    while (n != 0)
    {
        if (abs(ant) % 10 == abs(n) % 10)
            cnt++;
        ant = n;
        cin >> n;
    }
    cout << cnt;
    return 0;
}