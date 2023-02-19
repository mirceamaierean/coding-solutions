#include <fstream>
#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#include <vector>
using namespace std;

ifstream fin("expr.in");
ofstream fout("expr.out");

deque<int> v[12005];
string a;
size_t j;
stack<int> eval;
int cnt;
/* codificam operatorii : -1: (
                          -2: )
                          -3: *
                          -4: +
                          -5: -
                          -6 %
*/

int main()
{
    fin >> a;
    a += ')';
    int size = a.size();
    eval.push(-1);
    for (int i = 0; i < size; ++i)
    {
        if (a[i] == '{')
        {
            while (i < size && a[i] != '}')
            {
                int nr = 0;
                bool ok = false;
                while (i < size && isdigit(a[i]))
                {
                    nr = nr * 10 + a[i] - '0';
                    ++i;
                    ok = true;
                }
                if (a[i] != '}')
                    ++i;
                if (ok)
                    v[cnt].push_back(nr);
            }
            eval.push(cnt);
            cnt++;
        }
        else if (a[i] == '(')
            eval.push(-1);
        else if (a[i] == '*')
            eval.push(-3);
        else if (a[i] == '+')
            eval.push(-4);
        else if (a[i] == '-')
            eval.push(-5);
        else if (a[i] == '%')
            eval.push(-6);
        else
        {
            deque<int> valori;

            while (!eval.empty() && eval.top() != -1)
            {
                valori.push_front(eval.top());
                eval.pop();
            }

            eval.pop();

            deque<int> v1;
            deque<int> val;

            v1 = v[valori[0]];

            for (size_t j = 0; j < valori.size(); ++j)
            {

                if (valori[j] == -3)
                {
                    val.clear();
                    set_intersection(v1.begin(), v1.end(), v[valori[j + 1]].begin(), v[valori[j + 1]].end(), back_inserter(val));
                    v1 = val;
                }
                else if (valori[j] == -4)
                {
                    val.clear();
                    set_union(v1.begin(), v1.end(), v[valori[j + 1]].begin(), v[valori[j + 1]].end(), back_inserter(val));
                    v1 = val;
                }
                else if (valori[j] == -5)
                {
                    val.clear();
                    set_difference(v1.begin(), v1.end(), v[valori[j + 1]].begin(), v[valori[j + 1]].end(), back_inserter(val));
                    v1 = val;
                }
                else if (valori[j] == -6)
                {
                    val.clear();
                    set_symmetric_difference(v1.begin(), v1.end(), v[valori[j + 1]].begin(), v[valori[j + 1]].end(), back_inserter(val));
                    v1 = val;
                }
            }
            v[cnt] = v1;
            eval.push(cnt);
            cnt++;
        }
    }

    cnt--;
    fout << "{";
    if (v[cnt].size())
        fout << v[cnt][0];
    for (size_t i = 1; i < v[cnt].size(); ++i)
        fout << "," << v[cnt][i];
    fout << "}\n";
    return 0;
}
