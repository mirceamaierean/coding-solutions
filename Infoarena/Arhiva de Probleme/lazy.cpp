#include <fstream>

using namespace std;

ifstream fin("hotel.in");
ofstream fout("hotel.out");

int val, L, R, maxi, v, q;

struct arb
{
    int lazy, l_s, l_d, l_max;
};

const int NMAX = 100001;

arb a[4 * NMAX];

void build(int nod, int left, int right)
{
    if (left == right)
    {
        a[nod].l_s = a[nod].l_d = a[nod].l_max = 1;
        return;
    }

    int m = (left + right) / 2;

    build(2 * nod, left, m);
    build(2 * nod + 1, m + 1, right);

    a[nod].l_s = a[nod].l_d = a[nod].l_max = right - left + 1;
}

void update(int nod, int left, int right)
{
    if (a[nod].lazy == 1)
    {
        a[nod].l_s = a[nod].l_d = a[nod].l_max = 0;
        a[nod].lazy = -1;
        if (left != right)
            a[2 * nod].lazy = a[2 * nod + 1].lazy = 1;
    }
    else if (a[nod].lazy == 0)
    {
        a[nod].l_s = a[nod].l_d = a[nod].l_max = right - left + 1;
        a[nod].lazy = -1;
        if (left != right)
            a[2 * nod].lazy = a[2 * nod + 1].lazy = 0;
    }
    if (left > R || right < L)
        return;

    if (L <= left && right <= R)
    {
        if (q == 1)
        {
            a[nod].l_d = a[nod].l_s = a[nod].l_max = 0;
            if (left != right)
                a[2 * nod].lazy = a[2 * nod + 1].lazy = 1;
        }
        else
        {
            a[nod].l_d = a[nod].l_s = a[nod].l_max = right - left + 1;
            if (left != right)
                a[2 * nod].lazy = a[2 * nod + 1].lazy = 0;
        }
        return;
    }

    int m = (left + right) / 2;

    update(2 * nod, left, m);
    update(2 * nod + 1, m + 1, right);

    a[nod].l_max = max(max(a[2 * nod].l_max, a[2 * nod + 1].l_max), a[2 * nod].l_d + a[2 * nod + 1].l_s);
    a[nod].l_s = (a[2 * nod].l_max == m - left + 1) ? a[2 * nod].l_max + a[2 * nod + 1].l_s : a[2 * nod].l_s;
    a[nod].l_d = (a[2 * nod + 1].l_max == right - m) ? a[2 * nod + 1].l_max + a[2 * nod].l_d : a[2 * nod + 1].l_d;
}
int n, p, i, m;

int main()
{
    fin >> n >> p;

    build(1, 1, n);

    while (p--)
    {
        fin >> q;
        if (q == 3)
            fout << a[1].l_max << "\n";
        else
        {
            fin >> L >> R;

            R = L + R - 1;

            update(1, 1, n);
        }
    }
    return 0;
}
