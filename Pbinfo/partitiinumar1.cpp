#include <fstream>
int n;
using namespace std;
ifstream cin("partitiinumar1.in");
ofstream cout("partitiinumar1.out");
int v[50];
void afisare(int p)
{
    for (int i = 1; i <= p; ++i)
        cout << v[i] << " ";
    cout << '\n';
}
int valid(int p)
{
    int sum = 0;
    for (int i = 1; i <= p; ++i)
        sum += v[i];
    if (sum > n)
        return 2;
    if (sum < n)
        return 0;
    if (sum == n)
        return 1;
}
void back(int p)
{
    int pval;
    for (pval = v[p - 1] + 1; pval <= n; ++pval)
    {
        v[p] = pval;
        if (valid(p) == 1)
            afisare(p);
        if (valid(p) == 0)
            back(p + 1);
    }
}

int main()
{

    cin >> n;
    back(1);
    return 0;
}
