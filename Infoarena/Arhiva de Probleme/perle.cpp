#include <fstream>

using namespace std;

ifstream fin("perle.in");
ofstream fout("perle.out");

int j, a;
char s[10004];
bool ok;

void recursiv_b();

void recursiv_c();

int main()
{
    int n;

    fin >> n;

    while (n--)
    {
        char l;
        fin >> a;

        for (int i = 1; i <= a; ++i)
            fin >> s[i];

        ok = true;

        if (a == 1)
        {
            fout << ok << "\n";
            continue;
        }

        j = 1;

        if (s[1] == '1')
        {
            if (a == 3)
                recursiv_c();
            else
                recursiv_b();
        }
        else if (s[1] == '2')
            recursiv_b();
        else
            recursiv_c();
        if (j != a)
            ok = false;

        fout << ok << "\n";
    }
    return 0;
}

void recursiv_b()
{
    if (j > a)
        return;

    if (s[j] == '2')
    {
        ++j;
        recursiv_b();
    }
    else if (s[j] == '1' && s[j + 2] == '3')
    {
        j += 4;
        recursiv_c();
    }
    else
        ok = false;
}

void recursiv_c()
{
    if (s[j] == '2')
        return;
    if (s[j] == '1' && s[j + 1] == '2')
    {
        j += 2;
        return;
    }
    if (s[j] == '3')
    {
        ++j;
        recursiv_b();
        ++j;
        recursiv_c();
    }
    else
        ok = false;
}