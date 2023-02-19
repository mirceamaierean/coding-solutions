#include <fstream>
#include <vector>
using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

const int NMAX = 2000005;
string a, b;
int p[NMAX], cnt, size_a, size_b;
vector<int> v;

void kmp()
{
    int k = 0;
    for (int i = 1; i <= size_b; ++i)
    {
        while (k && a[k + 1] != b[i])
            k = p[k];

        if (a[k + 1] == b[i])
            ++k;

        if (k == size_a)
        {
            cnt++;
            if (cnt <= 1000)
                v.push_back(i - size_a);
        }
    }
}

void make_prefix()
{
    int k = 0;
    for (int i = 2; i <= size_a; ++i)
    {
        while (k && a[k + 1] != a[i])
            k = p[k];

        if (a[k + 1] == a[i])
            ++k;

        p[i] = k;
    }
}

int main()
{
    fin >> a >> b;

    size_a = a.size();
    size_b = b.size();

    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);

    make_prefix();

    kmp();

    fout << cnt << "\n";

    for (size_t i = 0; i < v.size(); ++i)
        fout << v[i] << " ";

    return 0;
}
