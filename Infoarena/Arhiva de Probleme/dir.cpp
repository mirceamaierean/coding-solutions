#include <fstream>
#include <iostream>
#include <set>
using namespace std;

ifstream fin("dir.in");
ofstream fout("dir.out");

string a;
int i;

set<string> af;

inline bool ok1(char a)
{
    return a == '(' || a == ')' || a == ',';
}

void mica(string b)
{
    b += char(92);
    string cop = b;
    bool ok = false;
    while (a[i])
    {
        if (!ok1(a[i]))
        {
            while (!ok1(a[i]))
            {
                if (islower(a[i]))
                    ok = true;
                b += a[i];
                ++i;
            }
        }
        else if (a[i] == '(')
        {
            ++i;
            mica(b);
            ++i;
        }
        else if (a[i] == ')')
        {
            if (ok)
                af.insert(b);
            ok = false;
            return;
        }
        else
        {
            if (ok)
                af.insert(b);
            ok = false;
            b = cop;
            ++i;
        }
    }
}

void eval()
{
    string b = "";
    while (a[i])
    {
        if (a[i] == '(')
        {
            ++i;
            mica(b);
            ++i;
        }
        else
        {
            b += a[i];
            ++i;
        }
    }
}

int main()
{
    fin >> a;
    eval();
    fout << af.size() << "\n";
    set<string>::iterator it = af.begin();
    for (; it != af.end(); ++it)
        fout << *it << "\n";
    return 0;
}
