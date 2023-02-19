#include <fstream>
using namespace std;

ifstream fin("farfurii.in");
ofstream fout("farfurii.out");

long long n, k;

long long caut()
{
    long long st = 1, dr = n, mij;
    while (st <= dr)
    {
        mij = (st + dr) >> 1LL;
        if (mij * (mij + 1) / 2 > k)
            dr = mij - 1;
        else
            st = mij + 1;
    }
    return dr;
}

int main()
{
    fin >> n >> k;
    long long poz = caut();

    long long inv = (poz * (poz + 1)) >> 1LL;
    k -= inv;

    for (int i = 1; i <= n - poz - 2; ++i)
        fout << i << " ";

    long long ind = n - poz - 1 + k;

    if (ind)
        fout << ind << " ";

    for (int i = n; i > n - poz - 2; --i)
        if (i != ind)
            fout << i << " ";

    return 0;
}
