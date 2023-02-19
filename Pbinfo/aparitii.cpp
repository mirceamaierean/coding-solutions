#include <iostream>

using namespace std;

int main()
{
    unsigned int a, fin, cnt = 0;
    cin >> a;
    fin = a % 10;
    cnt++;
    while (a > 9)
    {
        a = a / 10;
        if (a % 10 == fin)
            cnt++;
    }
    cout << cnt;
    return 0;
}
