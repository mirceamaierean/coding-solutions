#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[25];
    cin.getline(a, 25);
    for (int i = strlen(a) - 1; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
            cout << a[j];
        cout << "\n";
    }
    for (int i = 0; i < strlen(a); ++i)
    {
        cout << a + i << '\n';
    }
    return 0;
}
