#include <fstream>
using namespace std;
ifstream cin("sum.in");
ofstream cout("sum.out");
int main()
{
  int a, b;
  cin >> a >> b;
  cout << a + b;
  return 0;
}