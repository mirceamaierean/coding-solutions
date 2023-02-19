#include <fstream>
#include <stdlib.h>
using namespace std;

const int NMAX = 2 * 1e5 + 2;

std::ifstream fin("apm.in");
std::ofstream fout("apm.out");

typedef struct nod
{
    int rank;
    int key;
    nod *p;
} NodeT;

nod *a[NMAX];

struct muchie
{
    int c1;
    int c2;
    int cost;
};

struct arbore
{
    int x, y;
};

muchie g[2 * NMAX];
arbore v[NMAX];

int t[NMAX];

void MAKE_SET(int x)
{
    a[x] = (nod *)malloc(sizeof a[x]);
    a[x]->key = x;
    a[x]->rank = 0;
    a[x]->p = a[x];
}

NodeT *&FIND_SET(NodeT *&x)
{
    if (x == x->p)
        return x;
    return x->p = FIND_SET(x->p);
}

void LINK(NodeT *&x, NodeT *&y)
{
    if (x->rank > y->rank)
        y->p = x;
    else
    {
        x->p = y;
        if (x->rank == y->rank)
            y->rank++;
    }
}

void UNION(int x, int y)
{
    LINK(FIND_SET(a[x]), FIND_SET(a[y]));
}

int n, m;

int cmp(const void *a, const void *b)
{
    muchie m1 = *(const muchie *)a;
    muchie m2 = *(const muchie *)b;
    return m1.cost - m2.cost;
}

int main()
{
    fin >> n >> m;

    for (int i = 0; i < m; ++i)
        fin >> g[i].c1 >> g[i].c2 >> g[i].cost;

    for (int i = 1; i <= n; ++i)
        MAKE_SET(i);

    qsort(g, m, sizeof *g, cmp);

    int total(0);

    int ind = 0;

    for (int i = 0; i < m; ++i)
    {
        if (FIND_SET(a[g[i].c1]) != FIND_SET(a[g[i].c2]))
        {
            UNION(g[i].c1, g[i].c2);
            total += g[i].cost;
            v[ind].x = g[i].c1;
            v[ind++].y = g[i].c2;
        }
    }
    fout << total << "\n"
         << n - 1 << "\n";
    for (int i = 0; i < ind; ++i)
        fout << v[i].x << " " << v[i].y << '\n';
    return 0;
}
