#include <fstream>
int v[1001], d[1001], p[1001], n, k;
using namespace std;
ifstream cin("sclm.in");
ofstream cout("sclm.out");
void citire()
{
    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> v[i];
}
void afisare(int k)
{
    while (k > 0)
    {
        cout << k << " ";
        k = p[k];
    }
}
void dinamica()
{
    int i, j, max, max2 = n, poz;
    d[n] = 1;
    p[n] = 0;
    for (i = n - 1; i >= 1; --i)
    {
        poz = 0;
        max = 0;
        for (j = i + 1; j <= n; j++)
            if (v[i] < v[j] && d[j] > max)
            {
                max = d[j];
                poz = j;
            }
        d[i] = 1 + max;
        p[i] = poz;
        if (d[i] > d[max2])
            max2 = i;
    }
    cout << d[max2] << endl;
    afisare(max2);
}
int main()
{
    citire();
    dinamica();
    return 0;
}
