#include <iostream>
#include <string.h>
using namespace std;
bool iivocala(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return true;
    return false;
}
int main()
{
    bool ok = false;
    char a[120];
    cin.getline(a, 120);
    for (int i = 0; i < strlen(a); ++i)
    {
        if (iivocala(a[i]))
        {
            ok = true;
            break;
        }
    }
    if (ok == false)
        cout << "FARA VOCALE";
    else
        for (int i = 0; i < strlen(a); ++i)
        {
            cout << a[i];
            if (iivocala(a[i]))
            {
                ok = true;
                cout << "*";
            }
        }
    return 0;
}
