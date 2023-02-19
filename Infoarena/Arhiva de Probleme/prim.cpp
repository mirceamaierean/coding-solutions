#include <fstream>
#include <bitset>
#define NMAX 10000000

using namespace std;

bitset<NMAX + 1> ciur;

ifstream fin("prim.in");
ofstream fout("prim.out");

int main()
{
    int n, cnt = 0;
    unsigned long long val;

    fin >> n;

    for (int i = 2; i <= NMAX / 2; ++i)
        if (ciur[i] == 0)
        {
            ++cnt;
            if (cnt > n)
            {
                val = i;
                break;
            }
            for (int j = i + i; j <= NMAX; j += i)
                ciur[j] = 1;
        }

    fout << val * val;

    return 0;
}