#include <fstream>
#define nmax 1000003

using namespace std;

int n, i, j;

long long T = 0;
int fi[nmax];

ifstream cin("fractii.in");
ofstream cout("fractii.out");

int main()
{
  cin >> n;

  for (i = 1; i <= n; i++)
    fi[i] = i - 1;
  fi[1] = 1;

  for (i = 2; i <= n; i++)
    for (j = i + i; j <= n; j += i)
      fi[j] -= fi[i];

  for (i = 1; i <= n; ++i)
    T += fi[i];

  cout << 2 * T - 1;

  cin.close();
  cout.close();

  return 0;
}
