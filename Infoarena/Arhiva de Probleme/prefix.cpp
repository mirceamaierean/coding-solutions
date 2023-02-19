#include <fstream>
#include <vector>
#include <string>

std::ifstream fin("prefix.in");
std::ofstream fout("prefix.out");

std::string a;

int solve()
{
    int n = a.size();

    a.insert(a.begin(), ' ');

    std::vector<int> pr(n + 1, 0);

    int k = 0, res = 0;

    for (int i = 2; i <= n; ++i)
    {
        while (k && a[k + 1] != a[i])
            k = pr[k];
        if (a[k + 1] == a[i])
            ++k;
        pr[i] = k;
        if (pr[i] && i % (i - pr[i]) == 0)
            res = std::max(res, i);
    }
    return res;
}

int main()
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> a;
        fout << solve() << "\n";
    }
    fout.close();
    return 0;
}
