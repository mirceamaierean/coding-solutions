#include <fstream>
int n;
using namespace std;
ifstream cin("suma35.in");
ofstream cout("suma35.out");
int v[350];
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
    for (pval = max(3, v[p - 1]); pval <= 5; pval += 2)
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
