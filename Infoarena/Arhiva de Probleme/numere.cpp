#include <fstream>

using namespace std;

ifstream fin("numere.in");
ofstream fout("numere.out");

inline bool joc(int a, int b)
{
    if (a < b)
        swap(a, b);
    if (a % b == 0)
        return 0;
    if (a / b == 1)
        return 1 - joc(b, a - b);
    return 0;
}

int t, a, b;

int main()
{
    fin >> t;
    while (t--)
    {
        fin >> a >> b;
        fout << joc(a, b) + 1 << "\n";
    }
    return 0;
}
