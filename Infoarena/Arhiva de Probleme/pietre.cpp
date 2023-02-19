#include <fstream>

using namespace std;

ifstream fin("pietre.in");
ofstream fout("pietre.out");

const int NMAX = 1e6 + 1;

int t, a, b, v[2 * NMAX], dif;

int main()
{
    dif = 1;
    for (int i = 1; i < NMAX; ++i)
        if (v[i] == 0)
        {
            v[i] = i + dif;
            v[i + dif] = i;
            ++dif;
        }
    fin >> t;
    while (t--)
    {
        fin >> a >> b;
        if (v[a] == b)
            fout << "2\n";
        else
            fout << "1\n";
    }
    return 0;
}