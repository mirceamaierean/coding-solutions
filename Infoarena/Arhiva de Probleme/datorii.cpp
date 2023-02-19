#include <fstream>
#define zeros(x) ((x ^ (x - 1)) & x)
#define NMAX 15005

int aib[NMAX];
int n;

void Add(int x, int val)
{
  for (int i = x; i <= n; i += zeros(i))
    aib[i] += val;
}

int Compute(int x)
{
  int suma = 0;
  for (int i = x; i; i -= zeros(i))
    suma += aib[i];
  return suma;
}

using namespace std;

ifstream cin("datorii.in");
ofstream cout("datorii.out");

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie();
  int m, a, q, x, y;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i)
  {
    cin >> a;
    Add(i, a);
  }

  for (int i = 1; i <= m; ++i)
  {
    cin >> q;
    if (q == 0)
    {
      cin >> x >> a;
      Add(x, -a);
    }
    else if (q == 1)
    {
      cin >> x >> y;
      cout << Compute(y) - Compute(x - 1) << "\n";
    }
  }

  return 0;
}