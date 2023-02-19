#include <iostream>
using namespace std;
int main()
{
  int i, n, S = 0;
  cin >> n;
  for (i = 1; i <= n; i++)
  {
    if (i % 2 == 1)
      S = S + i * (i + 1);
    else
      S = S - i * (i + 1);
  }
  cout << "Rezultatul este " << S;
  return 0;
}
