#include <iostream>
using namespace std;
int main()
{
  int n, s[1001], i, max;
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> s[i];
  max = s[1];
  for (i = 2; i <= n; i++)
    if (s[i] > max)
      max = s[i];
  cout << max;
  return 0;
}