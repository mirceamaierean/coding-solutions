#include <iostream>
using namespace std;
int main()
{
  int n, m, p = 1;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      cout << p * p << " ";
      p += 2;
    }
    cout << "\n";
  }
}