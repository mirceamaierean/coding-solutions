#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int t, n, a, x;

int main()
{
    fin >> t;
    while (t--)
    {
        x = 0;
        fin >> n;
        while (n--)
        {
            fin >> a;
            x ^= a;
        }
        if (x)
            fout << "DA\n";
        else
            fout << "NU\n";
    }
    return 0;
}
