
#include <fstream>
int st[100], n;
using namespace std;
ifstream cin("submultimi.in");
ofstream cout("submultimi.out");
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
        afisare(p);
        back(p + 1);
    }
}

int main()
{
    cin >> n;
    back(1);
    return 0;
}