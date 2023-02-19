#include <iostream>

using namespace std;

int cnt, n;

int main()
{
    cin >> n;
    while (n != 0)
    {
        if (n & 1)
        	cnt++;
        cin >> n;
    }
    cout << cnt;
    return 0;
}