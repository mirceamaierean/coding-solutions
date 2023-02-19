#include <fstream>

using namespace std;

ifstream fin("taxe.in");
ofstream fout("taxe.out");

int n;

int suma(int a)
{
  if (a == 0)
    return 0;
  return a + suma(a / 4);
}

int caut_binar(int left, int right)
{
  int mid = (left + right) / 2;
  int val = suma(mid);
  if (val == n)
    return mid;
  else if (val < n)
    return caut_binar(mid + 1, right);
  else
    return caut_binar(left, mid);
}

int main()
{
  fin >> n;

  n /= 4;

  fout << caut_binar(1, n) << "\n";

  return 0;
}