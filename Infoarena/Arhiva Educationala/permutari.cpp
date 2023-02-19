#include <fstream>
int st[100], n;
using namespace std;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

void afisare(int p)
{
    for (int i = 1; i <= p; ++i)
        fout << st[i] << " ";
    fout << '\n';
}
bool valid(int p)
{
    for (int i = 1; i < p; ++i)
        if (st[i] == st[p])
            return false;
    return true;
}
void back(int p)
{
    int pval;
    for (pval = 1; pval <= n; ++pval)
    {
        st[p] = pval;
        if (valid(p))
            if (p == n)
                afisare(p);
            else
                back(p + 1);
    }
}

int main()
{
    fin >> n;
    back(1);
    return 0;
}
