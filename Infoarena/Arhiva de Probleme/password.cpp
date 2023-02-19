#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("password.in");
ofstream fout("password.out");

int main()
{
    string a;
    int ind, mini = 0, p = 1, l = 1;
    fin >> a;
    int n = a.size();

    while (p < n && mini + l + 1 < n)
    {
        ind = p + l;
        if (ind >= n)
            ind -= n;
        if (a[mini + l] == a[ind])
            ++l;
        else if (a[mini + l] < a[ind])
        {
            p = p + l + 1;
            l = 0;
        }
        else
        {
            mini = max(mini + l + 1, p);
            p = mini + 1;
            l = 0;
        }
    }

    fout << mini << "\n";
    fout.close();
    return 0;
}
