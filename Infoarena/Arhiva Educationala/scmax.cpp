#include <fstream>
#include <stack>
#include <algorithm>
using namespace std;

ifstream fin("scmax.in");
ofstream fout("scmax.out");

const int NMAX = 100001;
const long long oo = 1e12;

long long a[NMAX], b[NMAX], d[NMAX];

stack<int> st;

void lis(int n)
{
    int maxi = 0;

    for (int i = 1; i <= n; ++i)
    {
        d[i] = lower_bound(b, b + n + 1, a[i]) - b;
        if (d[i] > maxi)
            maxi = d[i];
        b[d[i]] = a[i];
    }

    fout << maxi << "\n";

    for (int i = n; i; --i)
        if (d[i] == maxi)
        {
            st.push(a[i]);
            maxi--;
        }

    while (!st.empty())
    {
        fout << st.top() << " ";
        st.pop();
    }

    fout << "\n";
}
int main()
{
    int n;

    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
        b[i] = oo;
        d[i] = 0;
    }

    b[0] = 0;

    lis(n);

    return 0;
}
