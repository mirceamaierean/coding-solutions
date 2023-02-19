#include <fstream>

using namespace std;

ifstream fin("maxsecv.in");
ofstream fout("maxsecv.out");

int mx1, mx2, n, a, cnt;

int main()
{
    fin >> n;
    while (n--)
    {
        fin >> a;
        if (a)
            cnt++;
        else
        {
            if (cnt > mx1)
            {
                mx2 = mx1;
                mx1 = cnt;
            }
            else if (cnt > mx2)
                mx2 = cnt;
            cnt = 0;
        }
    }
    if (cnt > mx1)
    {
        mx2 = mx1;
        mx1 = cnt;
    }
    else if (cnt > mx2)
        mx2 = cnt;

    fout << mx1 + mx2 << "\n";
    return 0;
}
