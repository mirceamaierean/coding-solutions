#include <iostream>
using namespace std;
int ogl(int a)
{
    int nr = 0;
    while (a)
    {
        nr *= 10;
        nr += a % 10;
        a /= 10;
    }
    return nr;
}
int main()
{
    int n, a, p;
    bool ok = false;
    cin >> n >> a;
    a = ogl(a);
    for (int i = 1; i < n; ++i)
    {
        cin >> p;
        if (a == p)
        {
            ok = true;
            break;
        }
    }
    if (ok == true)
        cout << "DA";
    else
        cout << "NU";
    return 0;
}
