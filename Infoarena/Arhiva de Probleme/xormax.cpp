#include <fstream>
#include <vector>
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
        fin = fopen(nume, "r");
        sp = 4095;
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

InParser fin("xormax.in");
ofstream fout("xormax.out");
class Trie
{
public:
    Trie *children[2];

    void insert(int val, int k)
    {
        if (val < 0)
            return;

        bool c = ((1 << val) & k);

        if (children[c] == NULL)
            children[c] = new Trie();

        children[c]->insert(val - 1, k);
    }

    int count(int val, int k)
    {
        if (val < 0)
            return 0;

        bool c = ((1 << val) & k);
        c = 1 - c;

        if (children[c] == NULL)
            c = 1 - c;

        return (c << val) + children[c]->count(val - 1, k);
    }
};

Trie trie;

int n, st, dr, maxi;

int main()
{
    maxi = -1;
    trie.insert(22, 0);

    fin >> n;

    vector<int> x(n + 1);

    x[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        fin >> x[i];
        x[i] ^= x[i - 1];
        int max_tr = trie.count(22, x[i]);
        max_tr ^= x[i];

        if (max_tr > maxi)
        {
            maxi = max_tr;
            dr = i;
        }

        trie.insert(22, x[i]);
    }

    for (int i = dr - 1; i >= 0; --i)
    {
        if ((x[i] ^ x[dr]) == maxi)
        {
            st = i + 1;
            break;
        }
    }

    fout << maxi << " " << st << " " << dr << "\n";

    return 0;
}
