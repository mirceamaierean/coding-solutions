#include <fstream>
#include <string.h>
#define MOD 9901
using namespace std;

ifstream fin("subsiruri.in");
ofstream fout("subsiruri.out");

int nr[1005];
int L[1005];
int n;
int a[1005];
int Lmax, cnt;

int main()
{
    fin >> n;

    for (int i = 1; i <= n; ++i)
        fin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        L[i] = 1;
        nr[i] = 1;
        for (int j = 1; j < i; ++j)
            if (a[j] < a[i])
            {
                if (L[j] + 1 > L[i])
                {
                    L[i] = L[j] + 1;
                    if (L[i] > Lmax)
                        Lmax = L[i];
                    nr[i] = nr[j];
                }
                else if (L[j] + 1 == L[i])
                {
                    nr[i] += nr[j];
                    nr[i] %= MOD;
                }
            }
    }
    for (int i = 1; i <= n; ++i)
        if (L[i] == Lmax)
        {
            cnt += nr[i];
            cnt %= MOD;
        }

    fout << Lmax << "\n"
         << cnt << "\n";

    return 0;
}
