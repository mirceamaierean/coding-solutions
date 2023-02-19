#include <fstream>
#include <limits.h>
using namespace std;
ifstream cin("secvcresc.in");
ofstream cout("secvcresc.out");
int main()
{
    int n, a, cop = 0, cnt = 0, best = 0, poz = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        if (a > cop)
            ++cnt;
        else
            cnt = 1;
        if (cnt > best)
        {
            best = cnt;
            poz = i - cnt + 1;
        }
        cop = a;
    }
    cout << poz << " " << poz - 1 + best;
    return 0;
}
