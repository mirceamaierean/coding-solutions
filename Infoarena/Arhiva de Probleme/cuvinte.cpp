#include <fstream>

using namespace std;

ifstream fin("cuvinte.in");
ofstream fout("cuvinte.out");

const int NMAX = 204;

int L[NMAX], nr[NMAX], a[NMAX];
int n, k, maxi;

int main()
{
    maxi = 1;
    fin >> n >> k;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = n; i; --i)
    {
        nr[i] = L[i] = 1;
        for (int j = n; j > i; --j)
            if (a[j] > a[i])
            {
                if (L[j] + 1 > L[i])
                {
                    L[i] = L[j] + 1;
                    if (L[i] > maxi)
                        maxi = L[i];
                    nr[i] = nr[j];
                }
                else if (L[j] + 1 == L[i])
                    nr[i] += nr[j];
            }
    }
    int last = -1;
    for (int i = 1; i <= n; i++)
        if (L[i] == maxi && a[i] > last)
        {
            if (nr[i] < k)
                k -= nr[i];
            else
            {
                fout << i << " ";
                last = a[i];
                maxi--;
            }
        }
    return 0;
}
