#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;
int main()
{
    char s[101];
    cin.get(s, 101);
    cin.get();
    for (unsigned int i = 0; i < strlen(s); i++)
        if (isalpha(s[i]))
            cout << s[i];
    return 0;
}
