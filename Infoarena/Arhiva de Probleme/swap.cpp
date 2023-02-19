#include <fstream>
#include <queue>
#define NMAX 50003
using namespace std;

ifstream fin("swap.in");
ofstream fout("swap.out");

string a, b;
int fr[30];
int aib[NMAX], n;

void update(int p, int val)
{
    for (int i = p; i <= n; i += i & -i)
        aib[i] += val;
}

int query(int p)
{
    int suma = 0;
    for (int i = p; i; i -= i & -i)
        suma += aib[i];
    return suma;
}

int main()
{
    fin >> a >> b;
    n = a.size();

    for (int i = 0; i < n; ++i)
    {
        ++fr[a[i] - 'a'];
        --fr[b[i] - 'a'];
    }

    for (int i = 0; i <= 26; ++i)
        if (fr[i])
        {
            fout << "-1\n";
            return 0;
        }
    a = " " + a;
    b = " " + b;
    int cnt = 0;

    vector<deque<int>> poz(30);

    for (int i = 1; i <= n; ++i)
        poz[a[i] - 'a'].push_back(i);

    for (int i = 1; i <= n; ++i)
    {
        int p = poz[b[i] - 'a'].front();
        poz[b[i] - 'a'].pop_front();
        cnt += p - 1 - query(p);
        update(p, 1);
    }

    fout << cnt << "\n";
    return 0;
}
