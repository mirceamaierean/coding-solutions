#include <fstream>
using namespace std;

ifstream fin("12perm.in");
ofstream fout("12perm.out");

int t[6], n;

const int MOD = 1048576;

int main()
{
    fin >> n;
    t[1] = 1;
    t[2] = 2;
    t[3] = 6;
    t[4] = 12;
    for (int i = 5; i <= n; ++i)
    {
        t[5] = (t[4] + t[2] + 2 * (i - 2)) % MOD;
        if (i != n)
        {
            t[1] = t[2];
            t[2] = t[3];
            t[3] = t[4];
            t[4] = t[5];
        }
    }
    if (n <= 4)
        fout << t[n] << "\n";
    else
        fout << t[5] << "\n";
    fout.close();
    return 0;
}
