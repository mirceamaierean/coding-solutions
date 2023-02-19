#include <fstream>
#include <bitset>
using namespace std;
ifstream cin("ciffrecv.in");
ofstream cout("ciffrecv.out");
bitset<10> ciur;
int frecv[10];
int main()
{
    ciur[2] = 1;
    ciur[3] = 1;
    ciur[5] = 1;
    ciur[7] = 1;
    int n;
    while (cin >> n)
    {
        if (ciur[n] == 1)
            ++frecv[n];
    }
    for (int i = 7; i >= 2; --i)
        if (frecv[i])
        {
            cout << i << " " << frecv[i];
            break;
        }
    return 0;
}
