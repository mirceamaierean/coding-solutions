#include <iostream>
#include <string.h>

using namespace std;

char a[35], b[35], sablon[35];

bool vocala(char a)
{
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

int main()
{
    cin >> a >> b;
    for (int i = 0; a[i]; ++i)
        if (vocala(a[i]))
        {
            if (vocala(b[i]))
                sablon[i] = '*';
            else
                sablon[i] = '?';
        }
        else
        {
            if (vocala(b[i]))
                sablon[i] = '?';
            else
                sablon[i] = '#';
        }
    cout << sablon << '\n';
    return 0;
}
