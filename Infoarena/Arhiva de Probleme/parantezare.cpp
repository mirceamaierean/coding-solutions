#include <fstream>
#include <stack>
#include <vector>
using namespace std;

ifstream fin("parantezare.in");
ofstream fout("parantezare.out");

stack<int> st;

string a;

vector<int> v;

int main()
{
  fin >> a;

  v.resize(a.size() + 1);

  for (int i = 0; a[i]; ++i)
    if (a[i] == '(')
      st.push(i);
    else if (a[i] == ')')
    {
      int val = st.top();
      v[val] = i;
      st.pop();
    }

  int m, k;
  fin >> m;
  while (m--)
  {
    fin >> k;
    fout << v[k] << " ";
  }
  return 0;
}
