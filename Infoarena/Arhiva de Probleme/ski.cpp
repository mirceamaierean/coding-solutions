#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("schi.in");
ofstream fout("schi.out");

const int inf = 0x3f3f3f3f, Dim = 30005;

int aib[Dim], c[Dim], a[Dim];
int n;

void Update(int p, int val)
{
    for (int i = p; i <= n; i += i & -i)
        aib[i] += val;
}

int aib_bs(int k)
{
    int i = 0;
    for (int p = 1 << 15; p; p >>= 1)
        if (i + p <= n && aib[i + p] < k)
        {
            k -= aib[i + p];
            i += p;
        }

    return i + 1;
}

int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
        Update(i, +1); // 1 liber, 0 ocupat
    }

    int loc;
    for (int i = n; i; --i)
    {
        loc = aib_bs(a[i]);
        Update(loc, -1);
        c[loc] = i;
    }

    for (int i = 1; i <= n; ++i)
        fout << c[i] << '\n';
    return 0;
}
