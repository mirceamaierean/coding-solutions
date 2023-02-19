#include <iostream>

using namespace std;

bool vocala(char a)
{
    return a == 'a' || a == 'e' || a == 'u' || a == 'i' || a == 'o';
}

int main()
{
    int cnt = 0;
    char a[300];
    cin.getline(a, 300);
    for (int i = 1; a[i]; ++i)
    {
        cnt += (vocala(a[i - 1]) && vocala(a[i]));
    }
    cout << cnt << '\n';
    return 0;
}