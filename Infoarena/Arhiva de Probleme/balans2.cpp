#include <fstream>
#include <stack>

std::ifstream fin("balans2.in");
std::ofstream fout("balans2.out");

std::stack<int> st;

const int NMAX = 2 * 1e6 + 2;

std::string s;

char cop[NMAX], res[NMAX];

int n, pair[NMAX], l;

int main()
{
  fin >> l >> s;

  int cnt(0), ind = 1, last = 0;

  for (int i = 0; i < l; ++i)
  {
    if (s[i] == '(')
    {
      cnt++;
      cop[++n] = s[i];
      st.push(n);
    }

    else if (s[i] == ')')
    {
      --cnt;
      cop[++n] = s[i];
      if (!st.empty())
      {
        pair[st.top()] = n;
        st.pop();
      }
      else
        last = std::max(last, n);
    }

    else
    {
      if (cop[ind] == '(')
      {
        last = std::max(last, pair[ind]);
        cnt--;
      }
      else
        cnt++;
      ind++;
    }

    if (ind > last && cnt == 0)
      res[i] = '1';

    else
      res[i] = '0';
  }

  fout << res << "\n";

  fout.close();
  return 0;
}
