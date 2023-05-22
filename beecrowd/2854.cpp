#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string, vector<string> > la_familia;
map<string,bool> vizite;
int cnt;
int n,m;
void DFS(string a)
{
    vizite[a]=1;
    for(int i=0;i<la_familia[a].size();++i)
    if(vizite[la_familia[a][i]]==0)
    DFS(la_familia[a][i]);
}
void solve()
{
    string mem1,mem2,rel;
    cin>>n>>m;
    for(int i=1; i<=m; ++i)
    {
        cin>>mem1>>rel>>mem2;
        la_familia[mem1].push_back(mem2);
        la_familia[mem2].push_back(mem1);
        vizite[mem1]=0;
        vizite[mem2]=0;
    }
    map<string,bool>::iterator it;
    for(it=vizite.begin(); it!=vizite.end(); ++it)
        if(it->second==0)
        {
            ++cnt;
            DFS(it->first);
        }
    cout<<cnt<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
    return 0;
}

