#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream fin("bool.in");
ofstream fout("bool.out");

vector<int> v[30];
string a, b;
int n, i;

bool expresie();
bool expresie_sau();
bool expresie_si();

int main()
{
    getline(fin, a);
    fin >> n;
    int size = a.size();
    for (int i = 0; i < size; ++i)
    {
        string c = "";
        int poz_start = -1, cnt = 0;
        bool ok = false;
        while (i < size && a[i] != ' ')
        {
            if (a[i] != '(' && a[i] != ')')
            {
                if (ok == 0)
                    poz_start = i;
                ok = true;
                c += a[i];
            }
            else if (a[i] == '(')
                b += a[i];
            else
                cnt++;
            ++i;
        }

        if (c == "AND")
            b += '&';
        else if (c == "OR")
            b += '|';
        else if (c == "NOT")
            b += '!';
        else if (c == "TRUE")
            b += '1';
        else
            b += '0';
        if (c.size() == 1)
            v[c[0] - 'A'].push_back(b.size() - 1);

        while (cnt)
        {
            b += ')';
            cnt--;
        }
    }
    char c;
    b += ')';
    while (n--)
    {
        fin >> c;
        i = c - 'A';
        for (size_t j = 0; j < v[i].size(); ++j)
            b[v[i][j]] = (b[v[i][j]] == '0') + '0';
        i = 0;
        fout << expresie();
    }
    return 0;
}

bool expresie()
{
    bool val = expresie_sau();

    while (b[i] == '|')
    {
        ++i;
        val |= expresie_sau();
    }
    return val;
}

bool expresie_sau()
{
    bool val = expresie_si();
    while (b[i] == '&')
    {
        ++i;
        val &= expresie_si();
    }
    return val;
}

bool expresie_si()
{
    bool val, nu = 0;
    while (b[i] == '!')
    {
        nu = !nu;
        ++i;
    }
    if (b[i] == '1')
    {
        val = 1;
        ++i;
        if (nu)
            return !val;
        return val;
    }
    if (b[i] == '0')
    {
        val = 0;
        ++i;
        if (nu)
            return !val;
        return val;
    }
    if (b[i] == '(')
    {
        ++i;
        val = expresie();
        ++i;
        if (nu)
            return !val;
        return val;
    }
}