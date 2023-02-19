#include <fstream>
#include <vector>
#define ub(i) i & -i
using namespace std;

ifstream fin("evantai.in");
ofstream fout("evantai.out");

const int NMAX = 701;
const int MAX = 2001;
const int MOD = 30103;

int aib[NMAX][MAX], n;

void update(int x, int y, int val)
{
    for (int i = x; i <= n; i += ub(i))
        for (int j = y; j < MAX; j += ub(j))
        {
            aib[i][j] += val;
            if (aib[i][j] >= MOD)
                aib[i][j] -= MOD;
        }
}

int query(int x, int y)
{
    int s = 0;
    for (int i = x; i; i -= ub(i))
        for (int j = y; j; j -= ub(j))
        {
            s += aib[i][j];
            if (s >= MOD)
                s -= MOD;
        }
    return s;
}

vector<int> a;
int cnt, b[NMAX][NMAX];

int main()
{
    fin >> n;

    a.resize(n + 1);

    for (int i = 1; i <= n; ++i)
        fin >> a[i];

    for (int i = n - 1; i; --i)
        for (int j = n; j > i; --j)
        {
            b[i][j] = 1 + query(j - 1, a[j] + a[i] - 1);
            cnt += b[i][j];
            if (cnt >= MOD)
                cnt -= MOD;
            update(j, a[i] + a[j], b[i][j]);
        }

    fout << cnt << "\n";
    return 0;
}
