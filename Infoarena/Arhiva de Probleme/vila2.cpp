#include <vector>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("vila2.in");
ofstream fout("vila2.out");
deque<int> minQ;
deque<int> maxQ;
vector<int> a;
int n, k;

int main()
{
    fin >> n >> k;
    a = vector<int>(n); // constructorul clasei vector

    for (int i = 0; i < n; ++i)
        fin >> a[i];

    int difMax = -1;

    for (int i = 0; i < n; ++i)
    {
        while (!minQ.empty() && a[minQ.back()] > a[i])
            minQ.pop_back();
        minQ.push_back(i);

        if (i - minQ.front() > k)
            minQ.pop_front();

        while (!maxQ.empty() && a[maxQ.back()] < a[i])
            maxQ.pop_back();
        maxQ.push_back(i);

        if (i - maxQ.front() > k)
            maxQ.pop_front();

        if (a[maxQ.front()] - a[minQ.front()] > difMax)
            difMax = a[maxQ.front()] - a[minQ.front()];
    }
    fout << difMax << "\n";
    return 0;
}
