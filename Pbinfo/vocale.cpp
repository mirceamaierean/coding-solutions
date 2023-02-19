#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[25];
    cin.getline(a, 25);
    for (int i = 0; i < strlen(a); ++i)
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'o' || a[i] == 'i' || a[i] == 'u')
            cout << char(a[i] - 32);
        else
            cout << a[i];
    return 0;
}
