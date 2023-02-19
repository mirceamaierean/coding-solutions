#include <iostream>
#include <cstring>
using namespace std;

char s[300];
bool fr[30];

int main()
{
    cin.getline(s, 300);
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (fr[s[i] - 'a'] == 0)
            {
                fr[s[i] - 'a'] = 1;
                cout << s[i] << " ";
            }
        }
    }
    return 0;
}
