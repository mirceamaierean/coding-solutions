#include <fstream>
#include <bitset>
using namespace std;

ifstream fin("jocul.in");
ofstream fout("jocul.out");

const int NMAX = 100000;

bitset<NMAX + 2> dp;

int n, s, v[1001];

int main()
{
    fin >> n;
    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        s += v[i];
    }

    int s2 = s >> 1;

    for (int i = 1; i <= n; ++i)
        for (int j = s2 - v[i]; j >= 0; --j)
            if (dp[j])
                dp[j + v[i]] = 1;

    int i;

    for (i = s2; !dp[i]; --i)
        ;

    fout << i << " " << s - i << "\n";

    fout.close();
    return 0;
}
