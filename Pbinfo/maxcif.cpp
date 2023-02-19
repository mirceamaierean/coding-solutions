#include <fstream>
using namespace std;
ifstream cin("maxcif.in");
ofstream cout("maxcif.out");
int frec[10];
int main()
{
    int n, max = 0;
    while (cin >> n)
    {
        ++frec[n];
    }
    for (int i = 0; i <= 9; ++i)
        if (frec[i] > max)
            max = frec[i];
    for (int i = 0; i <= 9; ++i)
        if (frec[i] == max)
            cout << i << " ";
    return 0;
}
