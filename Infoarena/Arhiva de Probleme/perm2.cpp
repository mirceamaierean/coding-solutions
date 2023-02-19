#include <fstream>
#include <bitset>
#include <algorithm>
std::ifstream fin("perm2.in");
std::ofstream fout("perm2.out");

const int NMAX = 20002;

std::bitset<NMAX> viz;

int __gcd(int x, int y)
{
    if (x)
        return __gcd(y % x, x);
    return y;
}

int __lcm(int x, int y)
{
    return x * y / __gcd(std::min(x, y), std::max(x, y));
}

int a[NMAX];

int main()
{
    int n, k = 1;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];

    for (int i = 1; i <= n; ++i)
        if (a[i] != i && !viz[i])
        {
            int cnt(0);
            int j = i;
            while (!viz[j])
            {
                viz[j] = 1;
                j = a[j];
                ++cnt;
            }
            k = __lcm(k, cnt);
        }

    fout << k << "\n";

    fout.close();
    return 0;
}