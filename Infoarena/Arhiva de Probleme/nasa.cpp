#include <fstream>
#include <bitset>
#include <set>
#include <algorithm>
using namespace std;

const int NMAX = 46340;

ifstream fin("nasa.in");
ofstream fout("nasa.out");

bitset<100000005> nasa;
bitset<NMAX + 5> ciur;
int a, b;

int main()
{
    fin >> a >> b;

    long long cnt = b - a + 1;

    for (long long i = 4; i <= NMAX; i += 2)
        ciur[i] = 1;

    long long st = a / 4;

    if (st * 4 < a)
        ++st;

    st *= 4;

    for (long long i = st; i <= b; i += 4)
        if (nasa[i - a] == 0)
        {
            cnt--;
            nasa[i - a] = 1;
        }

    for (long long i = 3; i <= NMAX; i += 2)
        if (ciur[i] == 0)
        {
            for (long long j = i * i; j <= NMAX; j += i)
                ciur[j] = 1;

            int put = i * i;

            st = a / put;

            if (st * put < a)
                ++st;

            st *= put;

            for (long long j = st; j <= b; j += put)
            {
                if (nasa[j - a] == 0)
                {
                    nasa[j - a] = 1;
                    cnt--;
                }
            }
        }

    fout << cnt << "\n";

    return 0;
}
