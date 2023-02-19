#include <fstream>
#include <stack>
#include <vector>
using namespace std;

ifstream fin("editor.in");
ofstream fout("editor.out");

int main()
{
    int n;
    fin >> n;
    while (n--)
    {
        string a;
        fin >> a;
        vector<char> v;
        for (int i = 0; a[i]; ++i)
        {
            if (a[i] == '*')
            {
                if (v.size())
                    v.pop_back();
            }
            else if (a[i] != 'E')
                v.push_back(a[i]);
        }
        bool ok = true;
        int mici = 0, mari = 0;
        for (int i = 0; i < v.size(); ++i)
            if (v[i] == '(')
                mici++;
            else if (v[i] == '[')
                mari++;
            else if (v[i] == ')')
            {
                mici--;
                if (mici < 0 || (mici == 0 && v[i - 1] == '['))
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                mari--;
                if (mari < 0 || (mari == 0 && v[i - 1] == '('))
                {
                    ok = false;
                    break;
                }
            }
        if (mici || mari)
            ok = false;
        if (ok)
            fout << ":)\n";
        else
            fout << ":(\n";
    }
    return 0;
}
