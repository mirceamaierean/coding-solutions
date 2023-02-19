#include <iostream>

using namespace std;

const int NMAX = 1e5 + 1;

int a, b, prim[NMAX];

void ciuruire()
{
    prim[1] = 1;

    for (int i = 4; i <= b; i += 2)
        prim[i] = 1;

    for (int i = 3; i * i <= b; i += 2)
        if (prim[i] == 0)
            for (int j = i * i; j <= b; j += i)
                prim[j] = 1;
}

int main()
{
    cin >> a >> b;
    if (a > b)
        swap(a, b);

    ciuruire();

    for (int i = 1; i <= b; ++i)
    {
        prim[i] = 1 - prim[i];
        prim[i] += prim[i - 1];
    }

    cout << prim[b] - prim[a - 1] << '\n';

    return 0;
}