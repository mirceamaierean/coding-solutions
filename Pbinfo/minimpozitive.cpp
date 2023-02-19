#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
    int min = INT_MAX, n;
    cin >> n;
    while (n != 0)
    {
        if (n < min && n > 0)
            min = n;
        cin >> n;
    }
    if (min == INT_MAX)
        cout << "NU EXISTA";
    else
        cout << min;
    return 0;
}
