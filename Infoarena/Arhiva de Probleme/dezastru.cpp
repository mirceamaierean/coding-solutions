#include <fstream>
#include <iomanip>
using namespace std;

ifstream fin("dezastru.in");
ofstream fout("dezastru.out");

int n, k;

long long cnt;

double d[26];

long double r;

void back(int p, int ind, double s)
{
    if (ind <= n && p == k)
    {
        ++cnt;
        r += s;
        return;
    }
    for (int i = ind + 1; i <= n; ++i)
        back(p + 1, i, s * d[i]);
}

int main()
{
    fin >> n >> k;

    for (int i = 1; i <= n; ++i)
        fin >> d[i];

    back(0, 0, 1);

    r /= cnt;

    fout << fixed << setprecision(6) << r << "\n";

    fout.close();
    return 0;
}
