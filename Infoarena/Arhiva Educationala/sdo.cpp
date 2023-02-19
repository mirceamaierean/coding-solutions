#include <fstream>
#include <algorithm>
#define NMAX 4000005

using namespace std;

ifstream fin("sdo.in");
ofstream fout("sdo.out");

int v[NMAX], n, m;
int main()
{
    fin >> n >> m;

    for (int i = 1; i <= n; ++i)
        fin >> v[i];

    nth_element(v + 1, v + m, v + n + 1);

    fout << v[m] << "\n";

    return 0;
}
