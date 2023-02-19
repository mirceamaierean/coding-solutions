// 232
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[256];
    cin.getline(a, 256);
    for (int i = 0; i < strlen(a); ++i)
    {
        int j = i, punct = 0;
        while (j < strlen(a) && (isdigit(a[j]) || a[j] == '.'))
        {
            j++;
            if (a[j] == '.')
                punct = 1;
        }
        if (punct)
            i = j;
        if (i < strlen(a))
            cout << a[i];
    }
    return 0;
}
