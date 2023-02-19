#include <fstream>

using namespace std;

int f[200], n, v;
int main()
{
    ifstream cin("exp.in");
    ofstream cout("exp.out");

    int m;
    bool ok = true;

    cin >> m >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> v;
        while (v % 2 == 0)
        {
            f[2]++;
            v /= 2;
        }
        for (int j = 3; j * j <= v; j += 2)
        {
            while (v % j == 0)
            {
                f[j]++;
                v /= j;
            }
        }
        if (v > 1)
            f[v]++;
    }

    for (int i = 2; i <= 174; ++i)
        if (f[i] % m)
        {
            ok = false;
            break;
        }

    if (ok == false)
        cout << 0 << endl;

    else
    {
        cout << 1 << endl;
        for (int i = 2; i <= 174; ++i)
            if (f[i])
                cout << i << " " << f[i] / m << "\n";
    }

    return 0;
}
