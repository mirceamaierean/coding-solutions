#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("vocmax.in");
ofstream fout("vocmax.out");
int main()
{
    char s[301], t[301] = "";
    int n, maxim = 0;
    fin >> n;
    fin.get();
    for (int k = 1; k <= n; k++)
    {
        fin.getline(s, 301);
        int cnt = 0;
        for (int i = 0; i < strlen(s); i++)
        {
            if (strchr("aeiou", s[i]) != NULL)
                cnt++;
        }
        if (cnt >= maxim)
        {
            maxim = cnt;
            strcpy(t, s);
        }
    }
    fout << t << endl;
    return 0;
}