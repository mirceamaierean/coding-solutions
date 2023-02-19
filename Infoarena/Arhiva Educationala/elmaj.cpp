#include <fstream>
#include <map>
using namespace std;

class InParser
{
#pragma warning(disable : 4996)
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
        buff = new char[4096];
        fin = fopen(nume, "r");
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
InParser fin("elmaj.in");
ofstream fout("elmaj.out");

int elmaj = -1, cnt = 0, n, a;

map<int, int> fr;

int main()
{
    fin >> n;
    int cntel = (n >> 1);
    while (n--)
    {
        fin >> a;
        ++fr[a];
        if (fr[a] > cnt)
        {
            cnt = fr[a];
            if (cnt > cntel)
                elmaj = a;
        }
    }
    if (elmaj == -1)
        fout << "-1\n";
    else
        fout << elmaj << " " << cnt << "\n";
    fout.close();
    return 0;
}
