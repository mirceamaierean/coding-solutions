#include <fstream>

using namespace std;

ifstream fin("secvente.in");
ofstream fout("secvente.out");

int main()
{
    int n, a;
    for (int p = 1; p <= 3; ++p)
    {
        int cnt = 0;
        fin >> n;
        int fr[3] = {0};
        while (n--)
        {
            fin >> a;
            a %= 3;
            if (a == 0)
                cnt++;
            else
                fr[a % 3]++;
        }
        cnt += fr[1] / 3 * 3;
        fr[1] %= 3;
        cnt += fr[2] / 3 * 3;
        fr[2] %= 3;
        cnt += 2 * min(fr[1], fr[2]);
        fout << cnt << "\n";
    }
    return 0;
}
