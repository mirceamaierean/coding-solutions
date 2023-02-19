#include <fstream>
#include <stack>
#include <bitset>
#define I first
#define II second
#pragma warning(disable : 4996)
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

InParser fin("bile.in");
ofstream fout("bile.out");

int n;

typedef pair<int, int> p;

inline int convert(p a)
{
    return n * (a.I - 1) + a.II;
}

const int NMAX = 252;

bitset<NMAX> viz[NMAX];

inline bool ok(int x, int y)
{
    return x && y && x <= n && y <= n && viz[x][y] == 1;
}

struct nod
{
    int t;
    int f;
};
nod v[NMAX * NMAX];

stack<p> st;
stack<int> af;

p a;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int maxi;

inline int find(int x)
{
    if (x == v[x].t)
        return x;
    return v[x].t = find(v[x].t);
}

int main()
{
    fin >> n;

    for (int i = 1; i <= n * n; ++i)
    {
        fin >> a.I >> a.II;
        st.push(a);
        int val = convert(a);
        v[val].t = val;
        v[val].f = 1;
    }

    while (!st.empty())
    {
        a = st.top();
        int val = convert(a);
        st.pop();
        viz[a.I][a.II] = 1;
        af.push(maxi);
        int cnt = 1;
        stack<int> nr;
        nr.push(val);
        for (int i = 0; i < 4; ++i)
        {
            p b;
            b.I = a.I + dx[i];
            b.II = a.II + dy[i];
            if (ok(b.I, b.II))
            {
                int val2 = convert(b), r2 = find(val2), r1 = find(val);
                if (r1 != r2)
                    cnt += v[r2].f;
                if (r1 > r2)
                    v[r1].t = r2;

                else if (r1 < r2)
                    v[r2].t = r1;

                nr.push(r2);
            }
        }
        if (cnt > maxi)
            maxi = cnt;
        while (!nr.empty())
        {
            v[nr.top()].f = cnt;
            nr.pop();
        }
    }
    while (!af.empty())
    {
        fout << af.top() << "\n";
        af.pop();
    }
    return 0;
}
