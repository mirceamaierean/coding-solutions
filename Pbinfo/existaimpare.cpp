#include <iostream>

using namespace std;

int main()
{
    int n, s[101] = {0}, i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> s[i];
    for (i = 1; i <= n; i++)
        if (s[i] % 2 == 1)
            s[0] = 1;
    if (s[0] == 1)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
