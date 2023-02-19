#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

class InParser
{
private:
  FILE *fin;
  char *buff;
  int sp;
  char read()
  {
    ++sp;
    if (sp == 4096)
    {
      sp = 0;
      fread(buff, 1, 4096, fin);
    }
    return buff[sp];
  }

public:
  InParser(const char *nume)
  {
    fin = fopen(nume, "r");
    buff = new char[4096];
    sp = 4095;
  }
  InParser &operator>>(int &n)
  {
    char c;
    while (!isdigit(c = read()))
      ;
    n = c - '0';
    while (isdigit(c = read()))
      n = n * 10 + c - '0';
    return *this;
  }
};
InParser fin("matrice5.in");
ofstream fout("matrice5.out");

const int MOD = 10007;

const inline int min(const int &a, const int &b)
{
  if (a > b)
    return b;
  return a;
}

const inline int max(const int &a, const int &b)
{
  if (a < b)
    return b;
  return a;
}

const inline void Get_min(int &a, const int b)
{
  if (a > b)
    a = b;
}

const inline void Get_max(int &a, const int b)
{
  if (a < b)
    a = b;
}

inline int lgPow(int N, int P)
{
  int Ans = 1;
  for (; P; P >>= 1)
  {
    if (P & 1)
      Ans = (1LL * Ans * N) % MOD;
    N = (1LL * N * N) % MOD;
  }
  return Ans;
}

inline int Solve(int N, int M, int P, int K)
{

  return (1LL * lgPow(K * P, (N - 1) * (M - 1)) * lgPow(P, (N + M - 1))) % MOD;
}

int main()
{
  int T, N, M, P, K;

  fin >> T;

  while (T--)
  {
    fin >> N >> M >> P >> K;
    fout << Solve(N, M, P, K) << '\n';
  }
  return 0;
}