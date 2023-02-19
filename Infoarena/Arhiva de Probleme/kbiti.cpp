#include <fstream>
#include <string>
using namespace std;

ifstream fin("kbiti.in");
ofstream fout("kbiti.out");

int main()
{
  int t;
  string a;
  fin >> t;
  while (t--)
  {
    fin >> a;
    string::size_type sz;
    long long v = stoll(a, &sz, 2) + 1;
    fout << v << "\n";
  }
  return 0;
}
