#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int Lmax[40], pmax[40];
int t[20001];
string cuv[20003];
ifstream fin("text3.in");
ofstream fout("text3.out");

string a;
int maxi, pos, cnt;

void write(int pos)
{
  if (pos == 0)
    return;
  write(t[pos]);
  fout << cuv[pos] << "\n";
}

int main()
{
  cnt = 1;

  while (fin >> cuv[cnt])
    cnt++;

  cnt--;

  int L;
  for (int i = 1; i <= cnt; ++i)
  {
    int c = cuv[i][0] - 'a';
    L = Lmax[c] + 1;
    t[i] = pmax[c];
    c = cuv[i][cuv[i].length() - 1] - 'a';
    if (L > Lmax[c])
    {
      Lmax[c] = L;
      pmax[c] = i;
    }
  }
  for (char c = 0; c <= 'z' - 'a'; ++c)
    if (Lmax[c] > maxi)
    {
      maxi = Lmax[c];
      pos = pmax[c];
    }

  fout << cnt << "\n"
       << cnt - maxi << "\n";

  write(pos);

  return 0;
}