#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int i, n;
    char a[256];
    cin.getline(a, 256);
    n = strlen(a);
    for (i = 0; i <= n - 1; i++)
        if ((a[i + 1] == ' ' || a[i - 1] == ' ') && islower(a[i]))
            a[i] = a[i] - 32;
        else if (i == 0 || i == n - 1)
            a[i] = a[i] - 32;
    for (i = 0; i < n; i++)
        cout << a[i];
    return 0;
}
