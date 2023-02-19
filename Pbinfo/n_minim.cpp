#include <iostream>

using namespace std;

int main()
{
    int n, min, i, s[1001];
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> s[i];
    min = s[1];
    for (i = 2; i <= n; i++)
        if (s[i] < min)
            min = s[i];
    cout << min;
    return 0;
}
