#include <fstream>

using namespace std;
ifstream cin("iunie.in");
ofstream cout("iunie.out");
int main()
{
  int n;
  cin >> n;
  if (n % 2)
    cout << 0;
  else
    cout << n / 4;
  return 0;
}
