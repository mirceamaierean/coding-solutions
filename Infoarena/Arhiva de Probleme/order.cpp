#include <fstream>
#include <vector>
using namespace std;

ifstream fin("order.in");
ofstream fout("order.out");

vector<int> aib;

int n;

void update(int poz, int val)
{
    for (int i = poz; i <= n; i += (i & -i))
        aib[i] += val;
}

inline int query(int poz)
{
    int i = 0;
    for (int p = 1 << 15; p; p >>= 1)

        if (i + p <= n && aib[i + p] < poz)
        {
            poz -= aib[i + p];
            i += p;
        }

    return i + 1;
}

int main()
{
    fin >> n;
    aib.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        update(i, 1);

    int pos = 1, nr = n;
    for (int i = 1; i <= n; ++i)
    {
        pos += i;
        pos %= nr;
        pos = (pos == 0) ? nr : pos;

        int act = query(pos);

        update(act, -1);
        --nr;
        --pos;

        fout << act << " ";
    }
    return 0;
}
