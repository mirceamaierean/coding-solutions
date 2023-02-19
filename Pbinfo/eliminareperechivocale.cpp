#include <iostream>
#include <cstring>

using namespace std;

bool vocala(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return 1;
    return 0;
}

int main()
{
    char a[520];
    cin.getline(a, 520);
    for (int i = 0; i < strlen(a); ++i)
        if (!vocala(a[i]))
            cout << a[i];
        else
        {
            if (i + 1 < strlen(a) && vocala(a[i + 1]))
            {
                while (a[i] && vocala(a[i]))
                    i++;
            }
            if (i < strlen(a))
                cout << a[i];
        }
    return 0;
}
