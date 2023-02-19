#include <fstream>

using namespace std;

ifstream fin("disjoint.in");
ofstream fout("disjoint.out");

const int NMAX = 100001;

int t[NMAX], n, m;

int c, x, y;

int find(int x)
{
    if (x == t[x])
        return x;
    return t[x] = find(t[x]);
}

int main()
{
    fin >> n >> m;

    for (int i = 1; i <= n; ++i)
        t[i] = i;

    while (m--)
    {
        fin >> c >> x >> y;

        if (c == 2)
        {
            if (find(x) == find(y))
                fout << "DA\n";
            else
                fout << "NU\n";
        }

        else
        {
            int r1 = find(x);
            int r2 = find(y);

            if (r1 > r2)
                t[r1] = r2;
            if (r1 < r2)
                t[r2] = r1;
        }
    }

    return 0;
}
