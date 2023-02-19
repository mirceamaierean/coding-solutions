#include <fstream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("bleach.in");
ofstream fout("bleach.out");

int n, k, s;
long long p, cnt;

vector<int> a;

int main()
{
  fin >> n >> k;
  for (int i = 0; i < n; ++i)
  {
    fin >> s;
    a.push_back(s);
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < n; ++i)
  {
    if (cnt < a[i])
    {
      p += 1LL * a[i] - cnt;
      cnt = 1LL * a[i];
    }
    cnt += 1LL * a[i];
  }

  fout << p << "\n";

  return 0;
}
