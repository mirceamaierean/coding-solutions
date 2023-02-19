#include <fstream>
#include <vector>
#include <set>

std::ifstream fin("armonica.in");
std::ofstream fout("armonica.out");

int b;

typedef std::pair<long long, long long> PLL;

std::set<PLL> Div;

void makeDivisor(int n)
{
  std::vector<PLL> v;

  for (int i = 1; i * i <= n; ++i)
    if (n % i == 0)
      v.push_back({i, n / i});

  for (auto x : v)
    for (auto y : v)
    {
      Div.insert({x.first * y.first, x.second * y.second});
      Div.insert({x.first * y.second, x.second * y.first});
      Div.insert({x.second * y.first, x.first * y.second});
      Div.insert({x.second * y.second, x.first * y.first});
    }
}

int main()
{
  fin >> b;

  if (b & 1)
    makeDivisor(b);

  else
    makeDivisor((b >> 1));

  fout << Div.size() << '\n';

  for (auto x : Div)
    if (b & 1)
      fout << ((1LL * (b + x.first)) >> 1LL) << " " << ((1LL * (b + x.second)) >> 1LL) << "\n";
    else
      fout << (1LL * (x.first + (b >> 1))) << " " << (1LL * (x.second + (b >> 1))) << "\n";
  fout.close();
  return 0;
}
