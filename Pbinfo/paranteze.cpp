#include <fstream>
#include <cmath>
using namespace std;
int n;
char st[101];
ifstream cin("paranteze.in");
ofstream cout("paranteze.out");
void afisare()
{
    for (int i = 1; i <= n; ++i)
        cout << st[i];
    cout << '\n';
}
int valid(int p)
{
    int cnt = 1;
    for (int i = 2; i <= p; ++i)
    {
        if (st[i] == 40)
            ++cnt;
        else if (st[i] == 41)
            --cnt;
        if (cnt < 0)
            return 2;
    }
    if (p == n - 1 && cnt == 1)
        return 0;
    if (p < n - 1)
        return 1;
    return 2;
}
void back(int p)
{
    for (int pval = 40; pval <= 41; ++pval)
    {
        st[p] = pval;
        if (valid(p) == 0)
            afisare();
        else if (valid(p) == 1)
            back(p + 1);
    }
}

int main()
{
    cin >> n;
    if (n == 2)
        cout << "()";
    else
    {
        st[1] = 40;
        st[n] = 41;
        back(2);
    }
    return 0;
}
