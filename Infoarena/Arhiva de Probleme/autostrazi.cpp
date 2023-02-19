#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

ifstream fin("autostrazi.in");
ofstream fout("autostrazi.out");

const int MOD = 30011;

using VI = vector<int>;
VI r;
vector<VI> G;
int N, K;
int S;

VI Df(int x, int father)
{
  VI X(S + 1);

  X[0] = 1;

  for (const int &son : G[x])
  {
    if (son == father)
      continue;

    VI F = Df(son, x);
    VI A(S + 1);

    for (int i = 0; i <= K; ++i)
      for (int k = 0; k + r[i] <= S; ++k)
        for (int j = 0; k + r[i] + j <= S; ++j)
          if (j >= k + r[i])
          {
            A[j] += (X[j] * F[k]) % MOD;
            A[j] %= MOD;
          }
          else
          {
            A[k + r[i]] += (X[j] * F[k]) % MOD;
            A[k + r[i]] %= MOD;
          }
    X = A;
  }
  return X;
}

int main()
{
  fin >> N >> S >> K;

  G.resize(N + 1);
  r.resize(K + 1);

  for (int i = 1; i <= K; ++i)
    fin >> r[i];

  int x, y;

  for (int i = 0; i < N - 1; ++i)
  {
    fin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  fin.close();

  VI v = Df(1, 0);

  int sol = 0;

  for (int i = 0; i <= S; ++i)
  {
    sol += v[i];
    sol %= MOD;
  }

  fout << sol << '\n';
  fout.close();

  return 0;
}