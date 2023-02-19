// OK
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream fin("ture.in");
ofstream fout("ture.out");

const int Nmax = 256;
using LL = long long;

bool A[Nmax][Nmax];
bool B[Nmax][Nmax];
int n, m, k;
LL c[1 << 16], c1[1 << 16], sol;

void Dinamica()
{
    c[0] = 1;

    for (int i = 0; i < n; ++i)
    {
        memcpy(c1, c, sizeof(c));
        for (int j = 0; j < (1 << m); ++j)
            for (int k = 0; k < m; ++k)
                if (!A[i][k] && !((1 << k) & j))
                    c[j | (1 << k)] += c1[j];
    }
}

int nbit(int x)
{
    return x ? 1 + nbit(x & (x - 1)) : 0;
}

int main()
{
    fin >> n >> m >> k;
    int P, x, y;
    fin >> P;
    while (P--)
    {
        fin >> x >> y;
        x--, y--;
        A[x][y] = true;
    }

    if (n < m)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                B[j][i] = A[i][j];
        memcpy(A, B, sizeof(B));
        int aux = n;
        n = m;
        m = aux;
    }

    Dinamica();

    for (int i = 0; i < (1 << m); ++i)
        if (nbit(i) == k)
            sol += c[i];

    fout << sol << '\n';

    return 0;
}
