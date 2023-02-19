#include <fstream>
#include <vector>
#include <bitset>
#pragma warning(disable : 4996)
#define x first
#define y second
using namespace std;

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

InParser fin("stramosi.in");
ofstream fout("stramosi.out");

const int NMAX = 250003;

typedef pair<int, int> p;

vector<int> g[NMAX];
vector<p> q[NMAX];
vector<int> rad;
vector<int> query;
int n, m, a, b;
vector<int> st;

void DFS(int nod)
{
    st.push_back(nod);
    for (size_t i = 0; i < g[nod].size(); ++i)
    {
        int fiu = g[nod][i];
        for (size_t j = 0; j < q[fiu].size(); ++j)
        {
            int ind = q[fiu][j].second, str = q[fiu][j].first;

            if (str == 0)
                query[ind] = fiu;

            else if (str <= st.size())
                query[ind] = st[st.size() - str];
        }
        DFS(fiu);
    }
    st.pop_back();
}

int main()
{
    fin >> n >> m;

    st.reserve(n);

    for (int i = 1; i <= n; ++i)
    {
        fin >> a;
        if (a == 0)
            rad.push_back(i);
        else
            g[a].push_back(i);
    }

    query.resize(m);

    for (int i = 0; i < m; ++i)
    {
        fin >> a >> b;
        q[a].push_back({b, i});
    }

    for (size_t i = 0; i < rad.size(); ++i)
        DFS(rad[i]);

    for (int i = 0; i < m; ++i)
        fout << query[i] << "\n";
    return 0;
}