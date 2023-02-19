#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#define NMAX 1026
#define MAXN 16385
using namespace std;
int a[NMAX][NMAX], alt[NMAX][NMAX];

vector<pair<int, int>> v[MAXN];
stack<pair<int, int>> st;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int fr[MAXN];
int n, cnt, maxi, cx, cy, hmax, mini;

int mem(int x, int y)
{
    int val = 0;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (a[nx][ny] < a[x][y] && alt[nx][ny] > val)
            val = alt[nx][ny];
    }
    return val + 1;
}

void schimba(int &x, int &y)
{
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (alt[nx][ny] + 1 == alt[x][y])
        {
            x = nx;
            y = ny;
            return;
        }
    }
}
class InParser
{
private:
    FILE *fin;
    char *buff;
    int sp;

    char read_ch()
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
        fin = fopen(nume, "r");
        buff = new char[4096]();
        sp = 4095;
    }
    InParser &operator>>(int &n)
    {
        char c;
        while (!isdigit(c = read_ch()) && c != '-')
            ;
        int sgn = 1;
        if (c == '-')
        {
            n = 0;
            sgn = -1;
        }
        else
            n = c - '0';
        while (isdigit(c = read_ch()))
            n = 10 * n + c - '0';
        n *= sgn;
        return *this;
    }
    InParser &operator>>(long long &n)
    {
        char c;
        n = 0;
        while (!isdigit(c = read_ch()) && c != '-')
            ;
        long long sgn = 1;
        if (c == '-')
        {
            n = 0;
            sgn = -1;
        }
        else
            n = c - '0';
        while (isdigit(c = read_ch()))
            n = 10 * n + c - '0';
        n *= sgn;
        return *this;
    }
};
int main()
{
    InParser fin("alpin.in");
    ofstream fout("alpin.out");
    mini = MAXN;
    fin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            fin >> a[i][j];
            if (a[i][j] > hmax)
                hmax = a[i][j];
            if (a[i][j] < mini)
                mini = a[i][j];
            v[a[i][j]].push_back(make_pair(i, j));
        }
    for (int j = mini; j <= hmax; ++j)
        for (size_t i = 0; i < v[j].size(); ++i)
        {
            int x = v[j][i].first, y = v[j][i].second;
            alt[x][y] = mem(x, y);
            if (alt[x][y] > maxi)
            {
                cx = x;
                cy = y;
                maxi = alt[x][y];
            }
        }
    fout << maxi << "\n";
    while (1)
    {
        st.push(make_pair(cx, cy));
        schimba(cx, cy);
        if (alt[cx][cy] == 1)
        {
            fout << cx << " " << cy << "\n";
            while (!st.empty())
            {
                fout << st.top().first << " " << st.top().second << "\n";
                st.pop();
            }
            return 0;
        }
    }
    return 0;
}
