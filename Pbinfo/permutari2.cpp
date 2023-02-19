#include <fstream>
#include <algorithm>
using namespace std;
int a[10], st[10];
int n;
ifstream fin("permutari2.in");
ofstream fout("permutari2.out");
void afiseaza()
{
    for (int i = 1; i <= n; ++i)
        fout << st[i] << " ";
    fout << "\n";
}
bool ok(int p)
{
    for (int i = 1; i < p; ++i)
        if (st[i] == st[p])
            return false;
    return true;
}
void back(int p)
{
    for (int i = 1; i <= n; ++i)
    {
        st[p] = a[i];
        if (ok(p))
        {
            if (p == n)
                afiseaza();
            else
                back(p + 1);
        }
    }
}
int main()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    sort(a + 1, a + n + 1);
    back(1);
    return 0;
}
