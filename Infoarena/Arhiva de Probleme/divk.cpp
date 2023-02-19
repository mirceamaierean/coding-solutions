#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("divk.in");
ofstream fout("divk.out");

int v[500001], f[99999];

int main()
{
    int n, a, b, k;
    long long cnt = 0;
    fin >> n >> k >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        int x;
        fin >> x;
        v[i] = (v[i - 1] + x) % k;
        if (i >= a)
            f[v[i - a]]++;
        if (i > b)
            f[v[i - b - 1]]--;
        cnt += f[v[i]];
    }
    fout << cnt;
    return 0;
}
