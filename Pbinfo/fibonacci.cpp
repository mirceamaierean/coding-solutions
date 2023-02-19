#include <iostream>
using namespace std;
int main()
{
  int n, i, s[41];
  cin >> n;
  s[1] = 1;
  s[2] = 1;
  for (i = 3; i <= n; i++)
    s[i] = s[i - 1] + s[i - 2];
  for (i = 1; i <= n; i++)
    cout << s[i] << " ";
  return 0;
}