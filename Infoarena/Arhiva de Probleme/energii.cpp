#include <fstream>
#include <limits.h>
#include <algorithm>
using namespace std;

ifstream fin("energii.in");
ofstream fout("energii.out");

const int WMAX = 5001;
const int MAX = 10005;
int optim[2 * WMAX];
int e, c, n, g, w;

int main()
{
    fin >> g >> w;
    for (int i = 1; i <= 2 * w; ++i)
        optim[i] = MAX;
    while (g--)
    {
        fin >> e >> c;
        for (int i = 2 * w - e; i >= 0; --i)
            optim[i + e] = min(optim[i + e], optim[i] + c);
    }
    int sol = MAX;
    for (int i = w; i <= 2 * w; ++i)
        sol = min(sol, optim[i]);
    if (sol == MAX)
        sol = -1;
    fout << sol << "\n";
    return 0;
}