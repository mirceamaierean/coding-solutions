#include <fstream>
using namespace std;
int n, t, v[] = {1, 2, 4, 7, 13, 25, 46, 86, 161, 300, 560, 1046, 1952, 3644, 6803, 12699, 23706, 44254, 82611, 154215, 287883, 537408, 1003212, 1872757, 3495988};
ifstream cin("football.in");
ofstream cout("football.out");
int main()
{
  cin >> t;
  for (int i = 1; i <= t; ++i)
  {
    cin >> n;
    cout << "Case " << i << ": " << v[n - 1] << "\n";
  }
  return 0;
}
