#include <fstream>
#include <stack>
using namespace std;

ifstream fin("nrpits.in");
ofstream fout("nrpits.out");

const int NMAX = 1e6 + 5;

struct pit
{
  int val, left, right;
};

pit a[NMAX];

int n;

stack<int> st;

int main()
{
  fin >> n;

  for (int i = 1; i <= n; ++i)
  {
    fin >> a[i].val;
    while (!st.empty() && a[st.top()].val < a[i].val)
    {
      a[st.top()].right = i;
      st.pop();
    }
    if (!st.empty())
      a[i].left = st.top();
    st.push(i);
  }

  unsigned long long cnt = 0;

  for (int i = 1; i <= n; ++i)
  {
    if (a[i].left && i - a[i].left >= 2)
      cnt++;
    if (a[i].right && a[i].right - i >= 2)
      cnt++;
  }

  fout << cnt << "\n";

  return 0;
}
