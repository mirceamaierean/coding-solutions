#include <fstream>
#include <bitset>
using namespace std;

ifstream fin("ciur.in");
ofstream fout("ciur.out");

int main()
{
    bitset<2000000> ciur;
    ciur.set();
    int n, cnt = 0;
    fin >> n;
    for (int i = 2; i <= n; i++)
        if (ciur[i])
            for (int j = i + i; j <= n; j = j + i)
                ciur[j] = 0;
    for (int i = 2; i <= n; i++)
        if (ciur[i])
            cnt++;
    fout << cnt;
    return 0;
}
