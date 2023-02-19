#include <fstream>

std::ifstream fin("semne.in");
std::ofstream fout("semne.out");

const int NMAX = 5 * 1e4 + 1;

char sgn[NMAX];

int n;
long long a[NMAX], _s, s;

bool solve(long long sum, int n)
{
    if (sum < s)
        return false;
    if (sum == s)
        return true;
    for (int i = n; i >= 0; --i)
    {
        sgn[i] = '-';
        if (solve(sum - 2 * a[i], i - 1))
            return true;
        sgn[i] = '+';
    }
    return false;
}

int main()
{
    fin >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        fin >> a[i];
        _s += a[i];
        sgn[i] = '+';
    }

    solve(_s, n - 1);

    fout << sgn << "\n";

    fout.close();
    return 0;
}
