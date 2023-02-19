#include <fstream>
int st[100], n, k;
using namespace std;
ifstream cin("combinari.in");
ofstream cout("combinari.out");
void afisare(int p)
{
    for (int i = 1; i <= p; ++i)
        cout << st[i] << " ";
    cout << '\n';
}
void back(int p)
{
    int pval;
    for (pval = st[p - 1] + 1; pval <= n; ++pval)
    {
        st[p] = pval;
        if (p == k)
            afisare(p);
        else
            back(p + 1);
    }
}

int main()
{
    cin >> n >> k;
    back(1);
    return 0;
}
