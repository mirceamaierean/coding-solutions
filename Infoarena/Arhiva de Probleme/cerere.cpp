#include <fstream>
#include <vector>
#include <bitset>
#pragma warning(disable : 4996)
using namespace std;

const int NMAX = 1e5 + 2;

class InParser
{
private:
    FILE *fin;
    char *buff;
    int sp;
    char read()
    {
        ++sp;
        if (sp == 4096)
        {
            sp = 0;
            fread(buff, 1, 4096, fin);
        }
        return buff[sp];
    }

public:
    InParser(const char *nume)
    {
        sp = 4095;
        fin = fopen(nume, "r");
        buff = new char[4096];
    }
    InParser &operator>>(int &n)
    {
        char c;
        while (!isdigit(c = read()))
            ;
        n = c - '0';
        while (isdigit(c = read()))
            n = n * 10 + c - '0';
        return *this;
    }
};

InParser fin("cerere.in");
ofstream fout("cerere.out");

int n, x, y;
vector<int> g[NMAX];
vector<int> k;
vector<int> st;
vector<int> str;
bitset<NMAX> viz;

void DFS(int nod)
{
    st.push_back(nod);
    viz[nod] = 1;

    for (size_t i = 0; i < g[nod].size(); ++i)
    {
        int fiu = g[nod][i];
        if (viz[fiu] == 0)
        {
            if (k[fiu])
            {
                int k_str = st[st.size() - k[fiu]];
                str[fiu] = str[k_str] + 1;
            }
            DFS(fiu);
        }
    }
    st.pop_back();
}

int main()
{
    fin >> n;

    long long rad = (1LL * n * (n + 1LL)) / 2;

    k.resize(n + 1);
    str.resize(n + 1);

    for (int i = 1; i <= n; ++i)
        fin >> k[i];

    for (int i = 1; i < n; ++i)
    {
        fin >> x >> y;
        if (viz[y] == 0)
        {
            viz[y] = 1;
            rad -= y;
        }
        g[x].push_back(y);
    }

    viz.reset();

    DFS(rad);

    for (int i = 1; i <= n; ++i)
        fout << str[i] << " ";

    return 0;
}
