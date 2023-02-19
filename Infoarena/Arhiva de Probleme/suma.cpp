#include <fstream>

using namespace std;

ifstream fin("suma.in");
ofstream fout("suma.out");

int main()
{
    long long n, p;
    fin >> n >> p;
    n %= p;
    fout << (n - 1) * n * (n + 1) / 3 % p;
    return 0;
}
