#include <iostream>
using namespace std;
int main()
{
    int n, i, s[101], max, min;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> s[i];
    max = s[1];
    min = s[1];
    for (i = 1; i <= n; i++)
    {
        if (s[i] > max)
            max = s[i];
        if (s[i] < min)
            min = s[i];
    }
    cout << min + max;
    return 0;
}