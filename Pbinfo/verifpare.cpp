#include <iostream>
using namespace std;
int main()
{
    int n, s[101], i, ok = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> s[i];
    for (i = 1; i <= n; i++)
        if (s[i] % 2 == 1)
            ok = 1;
    if (ok == 0)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}