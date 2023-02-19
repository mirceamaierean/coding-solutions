#include <fstream>
using namespace std;

ifstream cin("tabela.in");
ofstream cout("tabela.out");

int main()
{
    int n, m;
    cin >> n >> m;
    cout << ((n - 1) ^ (m - 1));
    return 0;
}
