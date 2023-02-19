#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>

using namespace std;

const int NMAX = 101;

typedef pair<double, int> qp;

vector<vector<pair<double, double>>> ins;
vector<int> g[NMAX];

int p, n, i, j;

double x1, x2, x3, y1, y2, y3, k, cost[NMAX][NMAX];

ifstream fin("elicoptere.in");
ofstream fout("elicoptere.out");

double checkX(double x1, double y1, double X1, double Y1, double X2, double Y2)
{
  double dist = k + 1;

  if (X1 <= x1 && x1 <= X2)
  {
    if (X1 == X2)
      dist = abs(min(Y1 - y1, Y2 - y1));
    else
    {
      double val = X1 * Y2 + x1 * Y1 - x1 * Y2 - X2 * Y1, down = X1 - X2;
      val /= down;
      dist = abs(val - y1);
    }
  }
  return dist;
}

double checkY(double x1, double y1, double X1, double Y1, double X2, double Y2)
{
  double dist = k + 1;

  if (Y1 > Y2)
  {
    swap(Y1, Y2);
    swap(X1, X2);
  }

  if (Y1 <= y1 && y1 <= Y2)
  {
    if (Y1 == Y2)
      dist = abs(min(X1 - x1, X2 - x1));
    else
    {
      double val = X2 * y1 + X1 * Y2 - X1 * y1 - X2 * Y1, down = Y2 - Y1;
      val /= down;
      dist = abs(val - x1);
    }
  }
  return dist;
}

bitset<NMAX> used;

int cnt = 0;

void DFS(int node)
{
  cnt++;
  used[node] = 1;
  for (auto x : g[node])
  {
    if (used[x] == 0)
      DFS(x);
  }
}

double APM(int node)
{
  priority_queue<qp, vector<qp>, greater<qp>> q;
  bitset<NMAX> used;
  used.reset();
  cnt--;

  for (auto i : g[node])
    q.push({cost[node][i], i});

  double costAPM = 0;

  used[node] = 1;

  while (cnt--)
  {
    while (!q.empty() && used[q.top().second] == 1)
      q.pop();

    qp crt = q.top();
    costAPM += crt.first;
    used[crt.second] = 1;

    for (auto i : g[crt.second])
      if (used[i] == 0)
        q.push({cost[crt.second][i], i});
  }

  return costAPM;
}

int main()
{
  fin >> p >> n >> k;
  for (i = 1; i <= n; ++i)
  {
    fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    vector<pair<double, double>> crt;

    crt.push_back({x1, y1});
    crt.push_back({x2, y2});
    crt.push_back({x3, y3});
    sort(crt.begin(), crt.end());

    x1 = crt[0].first;
    x2 = crt[1].first;
    x3 = crt[2].first;

    y1 = crt[0].second;
    y2 = crt[1].second;
    y3 = crt[2].second;

    for (j = 0; j < ins.size(); ++j)
    {
      vector<pair<double, double>> x = ins[j];

      double X1 = x[0].first, Y1 = x[0].second,
             X2 = x[1].first, Y2 = x[1].second,
             X3 = x[2].first, Y3 = x[2].second,
             minDist = k + 1;

      minDist = min(minDist, checkX(x1, y1, X1, Y1, X2, Y2));
      minDist = min(minDist, checkX(x1, y1, X1, Y1, X3, Y3));
      minDist = min(minDist, checkX(x1, y1, X2, Y2, X3, Y3));

      minDist = min(minDist, checkX(x2, y2, X1, Y1, X2, Y2));
      minDist = min(minDist, checkX(x2, y2, X1, Y1, X3, Y3));
      minDist = min(minDist, checkX(x2, y2, X2, Y2, X3, Y3));

      minDist = min(minDist, checkX(x3, y3, X1, Y1, X2, Y2));
      minDist = min(minDist, checkX(x3, y3, X1, Y1, X3, Y3));
      minDist = min(minDist, checkX(x3, y3, X2, Y2, X3, Y3));

      minDist = min(minDist, checkX(X1, Y1, x1, y1, x2, y2));
      minDist = min(minDist, checkX(X1, Y1, x1, y1, x3, y3));
      minDist = min(minDist, checkX(X1, Y1, x2, y2, x3, y3));

      minDist = min(minDist, checkX(X2, Y2, x1, y1, x2, y2));
      minDist = min(minDist, checkX(X2, Y2, x1, y1, x3, y3));
      minDist = min(minDist, checkX(X2, Y2, x2, y2, x3, y3));

      minDist = min(minDist, checkX(X3, Y3, x1, y1, x2, y2));
      minDist = min(minDist, checkX(X3, Y3, x1, y1, x3, y3));
      minDist = min(minDist, checkX(X3, Y3, x2, y2, x3, y3));

      minDist = min(minDist, checkY(x1, y1, X1, Y1, X2, Y2));
      minDist = min(minDist, checkY(x1, y1, X1, Y1, X3, Y3));
      minDist = min(minDist, checkY(x1, y1, X2, Y2, X3, Y3));

      minDist = min(minDist, checkY(x2, y2, X1, Y1, X2, Y2));
      minDist = min(minDist, checkY(x2, y2, X1, Y1, X3, Y3));
      minDist = min(minDist, checkY(x2, y2, X2, Y2, X3, Y3));

      minDist = min(minDist, checkY(x3, y3, X1, Y1, X2, Y2));
      minDist = min(minDist, checkY(x3, y3, X1, Y1, X3, Y3));
      minDist = min(minDist, checkY(x3, y3, X2, Y2, X3, Y3));

      minDist = min(minDist, checkY(X1, Y1, x1, y1, x2, y2));
      minDist = min(minDist, checkY(X1, Y1, x1, y1, x3, y3));
      minDist = min(minDist, checkY(X1, Y1, x2, y2, x3, y3));

      minDist = min(minDist, checkY(X2, Y2, x1, y1, x2, y2));
      minDist = min(minDist, checkY(X2, Y2, x1, y1, x3, y3));
      minDist = min(minDist, checkY(X2, Y2, x2, y2, x3, y3));

      minDist = min(minDist, checkY(X3, Y3, x1, y1, x2, y2));
      minDist = min(minDist, checkY(X3, Y3, x1, y1, x3, y3));
      minDist = min(minDist, checkY(X3, Y3, x2, y2, x3, y3));

      if (minDist <= k)
      {
        g[i].push_back(j + 1);
        g[j + 1].push_back(i);
        cost[i][j + 1] = minDist;
        cost[j + 1][i] = minDist;
      }
    }

    ins.push_back(crt);
  }

  int elicop = n, tot = 0;

  double costTotal = 0;

  for (int i = 1; i <= n; ++i)
    if (used[i] == 0)
    {
      cnt = 0;
      DFS(i);
      if (p == 3)
        costTotal += APM(i);
      tot += (cnt * (cnt - 1)) >> 1;
      --elicop;
    }

  if (p == 1)
    fout << elicop << '\n';

  else if (p == 2)
    fout << tot << '\n';

  else
    fout << fixed << setprecision(4) << costTotal << '\n';

  return 0;
}
