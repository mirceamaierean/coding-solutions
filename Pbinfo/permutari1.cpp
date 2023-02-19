#include <fstream>
int st[100], n;
using namespace std;
ifstream cin("permutari1.in");
ofstream cout("permutari1.out");
void afisare(int p)
{
    for (int i = 1; i <= p; ++i)
        cout << st[i] << " ";
    cout << '\n';
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
    for (pval = n; pval >= 1; --pval)
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
    cin >> n;
    back(1);
    return 0;
}
