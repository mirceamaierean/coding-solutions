#include <fstream>
#include <string.h>
using namespace std;

ifstream fin("text.in");
ofstream fout("text.out");

int main()
{
    int nrcuvinte = 0, nrlitere = 0;
    char c, lastChar = 0;

    while (fin >> noskipws >> c)
    {

        if (isalpha(c))
            nrlitere++;

        if (lastChar != 0)
            if (!isalpha(c) && isalpha(lastChar))
                nrcuvinte++;

        lastChar = c;
    }

    fout << nrlitere / nrcuvinte;

    return 0;
}
