#include <fstream>
#include <bitset>
#define NMAX 1000005

using namespace std;

bitset<1000000> ciur;
int query[NMAX + 5], num_div[NMAX + 5];

int main()
{
  ifstream fin("cufar.in");
  ofstream fout("cufar.out");
  int a, b, n, i;
  long long S = 0;
  char c;
  fin >> c;
  fin >> n;
  for (i = 1; i <= n; ++i)
  {
    fin >> a >> b;
    query[a] = b;
  }
  for (i = 2; i <= NMAX; ++i)
    if (!ciur[i])
    {
      for (int j = i; j <= NMAX; j += i)
      {
        ++num_div[j];
        ciur[j] = 1;
        if (num_div[j] == query[j])
          S += i;
      }
    }
  fout << S;
  return 0;
}
