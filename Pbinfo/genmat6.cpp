#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
    char a[10];
    cin.getline(a, 10);
    for (int i = 0; i < 2; ++i)
        swap(a[i], a[4 - i]);
    for (int i = 0; i <= 5; ++i)
    {
        for (int j = 0; j <= 5; ++j)
            if (i == j)
                cout << 0 << " ";
            else
                cout << a[min(i, j)] << " ";
        cout << "\n";
    }
    return 0;
}
