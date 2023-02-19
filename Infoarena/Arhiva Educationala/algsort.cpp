#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("algsort.in");
ofstream fout("algsort.out");

vector<int> v;

int main()
{
    int a, n;
    fin >> n;
    for (int i = 1; i <= n; ++i)
    {
        fin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
        fout << v[i] << " ";

    return 0;
}
