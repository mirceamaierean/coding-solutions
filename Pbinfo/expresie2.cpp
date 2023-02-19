#include <iostream>
using namespace std;
int main()
{
    int n, i = 2, s = 2;
    cin >> n;
    while (i <= n)
    {
        s = s + i * (i + 1);
        i++;
    }
    cout << "Rezultatul este " << s;
    return 0;
}
