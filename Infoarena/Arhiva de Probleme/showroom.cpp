#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;
ifstream fin("showroom.in");
ofstream fout("showroom.out");
const int MOD(9001);

int n, a, r, k, x, y, rx, ry, t[505], ind[505], cnt[505], fact[50005], nrd, nr, res = 1;
bool deja[505];
vector<int> dealeri;
string s, line;
unordered_map<string, bool> inM;
unordered_map<string, vector<int>> M;
unordered_map<string, int> dealer;
vector<vector<string>> vs;

inline int Find(int x)
{
  if (x == t[x])
    return x;
  return t[x] = Find(t[x]);
}
inline int powlog(int baza, int exp)
{
  int res = 1;
  while (exp > 0)
  {
    if (exp % 2)
      res = (1LL * res * baza) % MOD;
    exp /= 2;
    baza = (1LL * baza * baza) % MOD;
  }
  return res;
}
inline int invmod(int x)
{
  return powlog(x, MOD - 2);
}
inline int Comb(int n, int k)
{
  if (n <= k)
    return 1;
  int res = fact[n];
  res = res * invmod(fact[k]) % MOD;
  res = res * invmod(fact[n - k]) % MOD;
  return res;
}
int main()
{
  ios::sync_with_stdio(false);
  fin >> n >> a >> r >> k;
  for (int i = 1; i <= n; ++i)
    t[i] = i;
  fin.get();
  istringstream is;
  for (int i = 1; i <= n; ++i)
  {
    getline(fin, line);
    is.str(line);
    while (is >> s)
      if (inM.find(s) == inM.end())
        M[s].emplace_back(i), inM[s] = true;
    inM.clear();
    is.clear();
  }
  for (const auto &p : M)
  {
    x = p.second[0];
    for (size_t i = 1; i < p.second.size(); ++i)
    {
      y = p.second[i];
      rx = Find(x);
      ry = Find(y);
      if (rx > ry)
        t[rx] = ry;
      if (rx < ry)
        t[ry] = rx;
    }
  }
  for (const auto &p : M)
  {
    x = Find(p.second[0]);
    dealer[p.first] = x;
    if (!deja[x])
      dealeri.emplace_back(x), deja[x] = true;
  }
  M.clear();
  nrd = dealeri.size();
  sort(dealeri.begin(), dealeri.end());
  for (int i = 1; i <= nrd; ++i)
    ind[dealeri[i - 1]] = i;
  vs = vector<vector<string>>(nrd + 1);
  for (const auto &p : dealer)
    vs[ind[p.second]].emplace_back(p.first), ++cnt[ind[p.second]];
  fact[0] = 1;
  for (int i = 1; i <= 50000; ++i)
  {
    if (i % MOD == 0)
      fact[i] = ((i / MOD) * fact[i - 1]) % MOD;
    else
      fact[i] = (fact[i - 1] * i) % MOD;
  }

  for (int i = 1; i <= nrd; ++i)
  {
    res = (res * Comb(cnt[i], a)) % MOD;
    a = (a + r) % k;
  }

  fout << nrd << '\n'
       << res;
  fin.close();
  fout.close();
  return 0;
}
