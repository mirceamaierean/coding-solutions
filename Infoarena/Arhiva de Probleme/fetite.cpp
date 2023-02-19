#include <fstream>
using namespace std;

long long fetite(long long N)
{
  long long r;
  if (N == 1)
    return 1;
  if (N % 2 == 0)
    r = 2 * fetite(N / 2) - 1;
  else if (N % 2 != 0)
    r = 2 * fetite(N / 2) + 1;
  return r;
}

ifstream fin("fetite.in");
ofstream fout("fetite.out");

int main()
{
  long long N;
  fin >> N;
  fout << fetite(N);
  return 0;
}
