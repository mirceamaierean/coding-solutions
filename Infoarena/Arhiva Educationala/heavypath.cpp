#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("heavypath.in");
ofstream fout("heavypath.out");

using VI = vector<int>;
using VVI = vector<VI>;

class ST
{
public:
    ST(const VI &values)
    {
        for (N = 1; N < int(values.size()); N <<= 1)
            ;

        tree = VI(2 * N, 0);
        for (size_t i = 0; i < values.size(); ++i)
            tree[N + i] = values[i];
        for (int x = N - 1; x > 0; --x)
            tree[x] = max(tree[2 * x], tree[2 * x + 1]);
    }

    void Update(int where, const int value)
    {
        tree[where += N] = value;
        for (where >>= 1; where > 0; where >>= 1)
            tree[where] = max(tree[2 * where], tree[2 * where + 1]);
    }

    int Query(int l, int r) const
    {
        l += N;
        r += N;
        int vmax = 0;
        while (l <= r)
        {
            vmax = max(vmax, max(tree[l], tree[r]));
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        return vmax;
    }

private:
    int N;
    VI tree;
};

VVI T, paths;
int N;
VI v, t, nr, h, hmin, pId, pos;
vector<ST> st;

void DFS(const int x)
{
    int hs(0);
    nr[x] = 1;
    for (const auto &y : T[x])
    {
        if (y == t[x])
            continue;
        t[y] = x;
        h[y] = h[x] + 1;
        DFS(y);
        nr[x] += nr[y];
        if (hs == 0 || nr[y] > nr[hs])
            hs = y;
    }
    if (hs == 0)
    {
        pId[x] = int(paths.size());
        paths.push_back(vector<int>());
    }
    else
        pId[x] = pId[hs];

    pos[x] = int(paths[pId[x]].size());
    paths[pId[x]].push_back(x);
}

void BuildHeavyPath()
{
    t = pId = nr = h = pos = VI(N + 1);
    DFS(1);
    hmin = vector<int>(paths.size() + 1);

    for (size_t p = 0; p < paths.size(); ++p)
    {
        vector<int> pathValues;
        hmin[p] = h[paths[p].back()];
        for (const int &x : paths[p])
            pathValues.push_back(v[x]);

        st.push_back(ST(pathValues));
    }
}

int Query(int x, int y)
{
    if (pId[x] == pId[y])
    {
        if (pos[x] > pos[y])
            swap(x, y);

        return st[pId[x]].Query(pos[x], pos[y]);
    }
    if (hmin[pId[x]] < hmin[pId[y]])
        swap(x, y);

    return max(st[pId[x]].Query(pos[x], int(paths[pId[x]].size()) - 1),
               Query(t[paths[pId[x]].back()], y));
}

int main()
{
    int Q;
    fin >> N >> Q;
    v = VI(N + 1);
    T = VVI(N + 1);

    for (int x = 1; x <= N; ++x)
        fin >> v[x];

    for (int e = 1; e < N; ++e)
    {
        int x, y;
        fin >> x >> y;
        T[x].push_back(y);
        T[y].push_back(x);
    }

    BuildHeavyPath();

    int op, x, y, val;
    for (; Q > 0; --Q)
    {
        fin >> op;
        if (op == 0)
        {
            fin >> x >> val;
            v[x] = val;
            st[pId[x]].Update(pos[x], val);
        }
        else
        {
            fin >> x >> y;
            fout << Query(x, y) << "\n";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
