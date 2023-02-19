#include <iostream>
#include <string.h>
using namespace std;
int fr[10];
int main()
{
    char a[101];
    cin.getline(a, 101);
    for (int i = 0; i < strlen(a); ++i)
        if (isdigit(a[i]))
            ++fr[a[i] - '0'];
    int max = 0;
    for (int i = 0; i <= 9; ++i)
        if (fr[i] > max)
            max = fr[i];
    if (max == 0)
        cout << "NU";
    else
        for (int i = 0; i <= 9; ++i)
            if (fr[i] == max)
            {
                cout << i;
                break;
            }
    return 0;
}
