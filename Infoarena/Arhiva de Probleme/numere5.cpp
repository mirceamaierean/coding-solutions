#include <fstream>
#include <bitset>
using namespace std;

bitset<1000000> m;

int main()
{
    ifstream fin("numere5.in");
    ofstream fout("numere5.out");

    int a, n, min, max;
    fin >> n;

    for (int i = 1; i <= n * n; ++i)
    {
        fin >> a;
        m[a] = 1;
    }

    for (int i = 1; i <= n * n; ++i)
    {
        if (m[i] == 0)
        {
            min = i;
            break;
        }
    }

    for (int i = n * n; i > min; --i)
    {
        if (m[i] == 0)
        {
            max = i;
            break;
        }
    }

    fout << min << " " << max;

    return 0;
}
