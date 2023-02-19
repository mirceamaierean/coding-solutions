#include <fstream>
#include <stack>
#include <bitset>

std::ifstream fin("euler.in");
std::ofstream fout("euler.out");

const int NMAX = 262145;

int dad[NMAX], n, a, cnt;

bool ok;

std::stack<int> st;

std::bitset<NMAX> used;

int main()
{
    ok = true;
    fin >> n;
    while (fin >> a)
    {
        cnt++;
        if (used[a])
        {
            dad[st.top()] = a;
            st.pop();
            if (st.empty() || st.top() != a)
            {
                fout << "NU\n";
                return 0;
            }
        }
        else
            st.push(a);
        used[a] = 1;
    }
    if (cnt == 2 * n - 1)
    {
        fout << "DA\n";
        for (int i = 1; i <= n; ++i)
            fout << dad[i] << " ";
        fout << "\n";
    }
    else
        fout << "NU\n";
    fout.close();
    return 0;
}
