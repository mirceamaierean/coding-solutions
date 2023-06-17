#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string a,b,nume;
    int cnt=1,max=0;
    cin>>a;
    set<string> pr;
    set<string> npr;
    map<string,int> reg;
    while(a!="FIM")
    {
        cin>>b;
        if(b=="YES")
        {
            pr.insert(a);
            if(reg.find(a)==reg.end()) reg[a]=cnt;
            if(a.size()>max)
            {
                max=a.size();
                nume=a;
            }
            else if(a.size()==max&&reg[a]<reg[nume])
            {
                max=a.size();
                nume=a;
            }
        }
        else npr.insert(a);
        cin>>a;
    }
    for(set<string>::iterator it=pr.begin(); it!=pr.end(); ++it)
        cout<<*it<<"\n";
    for(set<string>::iterator it=npr.begin(); it!=npr.end(); ++it)
        cout<<*it<<"\n";
    cout<<"\nAmigo do Habay:\n"<<nume<<"\n";
    return 0;
}

