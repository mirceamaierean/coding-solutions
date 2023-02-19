#include <fstream>

using namespace std;

const int NMAX = 1004;

ifstream fin("expresie.in");
ofstream fout("expresie.out");

unsigned long long v[NMAX], s[NMAX], maxi;
int n;

int main()
{
  fin >> n;
  for (int i = 1; i <= n; ++i)
  {
    fin >> v[i];
    s[i] = v[i] + s[i - 1];
  }
  for (int i = 3; i <= n; ++i)
  {
    unsigned long long sum = v[i - 2] * v[i - 1] * v[i] + s[i - 3] + s[n] - s[i];
    if (sum > maxi)
      maxi = sum;
  }
  for (int i = 2; i < n - 1; ++i)
    for (int j = i + 2; j <= n; ++j)
    {
      unsigned long long sum = v[i - 1] * v[i] + v[j - 1] * v[j] + s[i - 2] + s[n] - s[j] + s[j - 2] - s[i];
      if (sum > maxi)
        maxi = sum;
    }
  fout << maxi << "\n";
  return 0;
}