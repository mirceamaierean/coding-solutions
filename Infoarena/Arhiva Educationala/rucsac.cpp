#include <fstream>

using namespace std;

ifstream fin("rucsac.in");
ofstream fout("rucsac.out");

const int GMAX = 10001;

int optim[GMAX];
int n, g, sol, w, p;

int main()
{
    fin >> n >> g;

    for (int i = 1; i <= n; ++i)
    {
        fin >> w >> p;
        for (int j = g - w; j >= 0; --j)
        {
            if (optim[j] + p > optim[j + w])
                optim[j + w] = optim[j] + p;
            if (optim[j + w] > sol)
                sol = optim[j + w];
        }
    }

    fout << sol;
    return 0;
}
