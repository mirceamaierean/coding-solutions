#include <fstream>

std::ifstream fin("damesah.in");
std::ofstream fout("damesah.out");

int n, st[20], cnt;

void print()
{
    for (int i = 1; i <= n; ++i)
        fout << st[i] << " ";
    fout << "\n";
}

bool col[20], d1[30], d2[30];

bool valid(int k)
{
    return col[st[k]] == 0 && d1[st[k] - k + n] == 0 && d2[k + st[k]] == 0;
}

void back(int lvl)
{
    for (int i = 1; i <= n; ++i)
    {
        st[lvl] = i;
        if (valid(lvl))
        {
            if (lvl == n)
            {
                cnt++;
                if (cnt == 1)
                    print();
            }
            else
            {
                col[st[lvl]] = 1;
                d1[st[lvl] - lvl + n] = 1;
                d2[st[lvl] + lvl] = 1;
                back(lvl + 1);
                col[st[lvl]] = 0;
                d1[st[lvl] - lvl + n] = 0;
                d2[st[lvl] + lvl] = 0;
            }
        }
    }
}

int main()
{
    fin >> n;
    back(1);
    fout << cnt << "\n";
    fout.close();
    return 0;
}
