#include <iostream>
#include <cstring>
using namespace std;

bool consoana(char a)
{
    a = tolower(a);
    return !(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

char a[25], b[25], c[50];

int ind;

int main()
{
    cin >> a >> b;
    for (int i = 0; i < strlen(b); ++i)
        if (consoana(b[i]))
        {
            c[ind] = b[i];
            ind++;
        }
    c[ind++] = ' ';
    for (int i = 0; a[i]; ++i)
        c[ind++] = a[i];

    cout << c;

    return 0;
}