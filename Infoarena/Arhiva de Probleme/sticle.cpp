#include <fstream>
#include <vector>
using namespace std;

vector<int> put2;

int bsearch2(int p, int u, int key)
{
    int m;
    while (p < u)
    {
        m = (p + u) / 2;
        if (put2[m] < key)
            p = m + 1;
        else
            u = m;
    }
    m = (p + u) / 2;
    if (put2[m] < key)
        ++m;
    return m;
}

ifstream fin("sticle.in");
ofstream fout("sticle.out");

int main()
{
    put2.push_back(1);

    for (int i = 2; i <= 100000; i *= 2)
        put2.push_back(i);
    int n, a;

    fin >> n;

    for (int i = 1; i <= n; ++i)
    {
        fin >> a;
        fout << bsearch2(0, put2.size() - 1, a) << "\n";
    }

    return 0;
}
