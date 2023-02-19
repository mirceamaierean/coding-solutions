#include <iostream>

using namespace std;
int ogl(int n)
{
    int nr = 0;
    while (n)
    {
        nr *= 10;
        nr += n % 10;
        n /= 10;
    }
    return nr;
}
int main()
{
    int n, max = -1, cnt = 0;
    cin >> n;
    while (n)
    {
        if (n == ogl(n))
        {
            if (n > max)
            {
                max = n;
                cnt = 1;
            }
            else if (n == max)
                ++cnt;
        }
        cin >> n;
    }
    if (max == -1)
        cout << "NU EXISTA";
    else
        cout << max << " " << cnt;
    return 0;
}
