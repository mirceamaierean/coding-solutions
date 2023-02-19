#include <fstream>

using namespace std;

ifstream fin("arbint.in");
ofstream fout("arbint.out");

const int NMAX = 100001;

int s[4 * NMAX], maxi;

void update(int x, int l, int r, int p, int val)
{
    if (l == r)
    {
        s[x] = val;
        return;
    }

    int m = (l + r) / 2;
    if (p <= m)
        update(2 * x, l, m, p, val);
    else
        update(2 * x + 1, m + 1, r, p, val);
    s[x] = max(s[2 * x], s[2 * x + 1]);
}

void query(int x, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        if (maxi < s[x])
            maxi = s[x];
        return;
    }

    int m = (l + r) / 2;
    if (L <= m)
        query(2 * x, l, m, L, R);
    if (m < R)
        query(2 * x + 1, m + 1, r, L, R);
}

int main()
{
    int a, n, q, b;
    fin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        fin >> a;
        update(1, 1, n, i, a);
    }

    while (q--)
    {
        char x;
        fin >> x >> a >> b;
        if (x == '1')
            update(1, 1, n, a, b);
        else
        {
            maxi = 0;
            query(1, 1, n, a, b);
            fout << maxi << "\n";
        }
    }
    return 0;
}
