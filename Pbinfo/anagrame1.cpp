#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
char a[10], st[10];
int n;
ifstream fin("anagrame1.in");
ofstream fout("anagrame1.out");
bool ok(int p)
{
    for (int i = 0; i < p; ++i)
        if (st[i] == st[p])
            return false;
    return true;
}
void back(int p)
{
    for (int i = 0; i < n; ++i)
    {
        st[p] = a[i];
        if (ok(p))
        {
            if (p == n - 1)
                fout << st << "\n";
            else
                back(p + 1);
        }
    }
}
int main()
{
    fin >> a;
    n = strlen(a);
    sort(a, a + n);
    back(0);
    return 0;
}
