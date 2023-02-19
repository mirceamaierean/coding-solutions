#include <fstream>
using namespace std;
ifstream cin("dreptunghi.in");
ofstream cout("dreptunghi.out");
unsigned long long suma, n, m;
void Rezolva()
{
  while (m && n)
  {
    int MIN = min(m, n);
    int MAX = max(m, n);
    suma += (MAX - MAX % MIN);
    if (m > n)
      m %= MIN;
    else
      n %= MIN;
  }
  cout << suma;
}
int main()
{
  cin >> n >> m;
  Rezolva();
  return 0;
}
