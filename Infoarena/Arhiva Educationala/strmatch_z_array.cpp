#include <fstream>
#include <vector>

using namespace std;

string a, b;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

void getZarr(string str, vector<int> &z)
{
    int n = str.length();

    int l, r, k;

    l = r = 0;

    for (int i = 1; i < n; ++i)
    {
        if (i > r)
        {
            l = r = i;

            while (r < n && str[r - l] == str[r])
                ++r;
            z[i] = r - l;

            --r;
        }

        else
        {
            k = i - l;

            if (z[k] < r - i + 1)
                z[i] = z[k];

            else
            {
                l = i;
                while (r < n && str[r - l] == str[r])
                    ++r;

                z[i] = r - l;

                --r;
            }
        }
    }
}

void search()
{
    string concat = a + "$" + b;
    int l = concat.length();

    vector<int> z(l);

    getZarr(concat, z);

    int cnt = 0;

    for (int i = 0; i < l; ++i)
        if (z[i] == a.length())
            ++cnt;

    fout << cnt << '\n';

    if (cnt > 1000)
        cnt = 1000;
    for (int i = 0; i < l; ++i)
        if (z[i] == a.length())
        {
            fout << i - a.length() - 1 << " ";
            --cnt;
            if (cnt == 0)
                return;
        }
}

int main()
{
    fin >> a >> b;

    search();

    return 0;
}
