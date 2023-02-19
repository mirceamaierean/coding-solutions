#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int NMAX = 1e5 + 2;
const unsigned long long oo = 6000000000000;

struct arb
{
    unsigned long long val, plus, poz;
};

int aib[NMAX], n, cd;
unsigned long long cnt, t;

arb ai[4 * NMAX];

ifstream fin("biscuiti.in");
ofstream fout("biscuiti.out");

void update_aib(int poz)
{
    for (int i = poz; i <= n; i += (i & -i))
        aib[i]++;
}

unsigned long long query(int poz)
{
    unsigned long long rez = 0;
    for (int i = poz; i; i -= (i & -i))
        rez += aib[i];
    return poz - rez;
}

void buildtree(int left, int right, int ind)
{
    if (left == right)
    {
        fin >> ai[ind].val;
        ai[ind].poz = left;
        return;
    }

    int mij = (left + right) / 2;

    buildtree(left, mij, 2 * ind);
    buildtree(mij + 1, right, 2 * ind + 1);

    if (ai[2 * ind].val <= ai[2 * ind + 1].val)
        ai[ind] = ai[2 * ind];
    else
        ai[ind] = ai[2 * ind + 1];
}

void update(int left, int right, int ind)
{
    if (left == right)
    {
        ai[ind].val = oo;
        return;
    }

    int mij = (left + right) / 2;

    if (mij < ai[1].poz)
        update(mij + 1, right, 2 * ind + 1);
    else
        update(left, mij, 2 * ind);

    if (ai[2 * ind].val + ai[2 * ind].plus <= ai[2 * ind + 1].val + ai[2 * ind + 1].plus)
    {
        ai[ind].val = ai[2 * ind].val + ai[2 * ind].plus;
        ai[ind].poz = ai[2 * ind].poz;
    }
    else
    {
        ai[ind].val = ai[2 * ind + 1].val + ai[2 * ind + 1].plus;
        ai[ind].poz = ai[2 * ind + 1].poz;
    }
}

void update_interval(int left, int right, int ind)
{
    if (right < 1 || left > cd || left > right)
        return;

    if (1 <= left && right <= cd)
    {
        ai[ind].plus += t;
        return;
    }

    int mij = (left + right) / 2;

    update_interval(left, mij, 2 * ind);
    update_interval(mij + 1, right, 2 * ind + 1);

    if (ai[2 * ind].val + ai[2 * ind].plus <= ai[2 * ind + 1].val + ai[2 * ind + 1].plus)
    {
        ai[ind].val = ai[2 * ind].val + ai[2 * ind].plus;
        ai[ind].poz = ai[2 * ind].poz;
    }
    else
    {
        ai[ind].val = ai[2 * ind + 1].val + ai[2 * ind + 1].plus;
        ai[ind].poz = ai[2 * ind + 1].poz;
    }
}

int main()
{
    fin >> n;

    buildtree(1, n, 1);

    for (t = 1; t <= n; ++t)
    {
        int ind = ai[1].poz;

        cd = ind - 1;

        cnt += query(cd) * t;

        update_aib(ind);

        update(1, n, 1);

        update_interval(1, n, 1);
    }

    fout << cnt << "\n";

    return 0;
}
