#include <iostream>
using namespace std;
int main()
{
    int n, max = 0;
    cin >> n;
    while (n != 0)
    {
        cin >> n;
        if (n > max)
            max = n;
    }
    if (max == 0)
        cout << "NU EXISTA";
    else
        cout << max;
    return 0;
}
