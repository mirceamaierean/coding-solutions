#include <fstream>
#include <bitset>

using namespace std;

ifstream fin("triplete.in");
ofstream fout("triplete.out");

const int NMAX = 4100;
const int PMAX = 65600;

bitset<NMAX> p[NMAX];

pair<int, int> m[PMAX];

int n, r, cnt;

int main()
{
    fin >> n >> r;
    for (int i = 1; i <= r; ++i)
    {
        fin >> m[i].first >> m[i].second;
        p[m[i].first][m[i].second] = 1;
        p[m[i].second][m[i].first] = 1;
    }

    for (int i = 1; i <= r; ++i)
        cnt += (p[m[i].first] & p[m[i].second]).count();

    fout << cnt / 3 << "\n";

    return 0;
}
