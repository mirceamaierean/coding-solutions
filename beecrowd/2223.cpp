#include <iostream>
#include <algorithm>
#include <string.h>
#define NMAX 100005
#define zeros(x)((x^(x-1))&x)
using namespace std;
int n;
long long aib[NMAX];
struct query1
{
    int poz;
    int x;
    int y;
    int k;
};
struct query2
{
    int x;
    long long val;
    bool facut;
};
void Add(int x,long long val)
{
    for(int i=x; i<=n; i+=zeros(i))
        aib[i]+=val;
}
long long query(int x)
{
    long long suma=0;
    for(int i=x; i; i-=zeros(i))
        suma+=aib[i];
    return suma;
}
inline bool cmp(query1 a,query1 b)
{
    if(a.k==b.k) return a.poz<b.poz;
    return a.k<b.k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int caz;
    cin>>caz;
    long long a[NMAX];
    while(caz--)
    {
        memset(aib,0,sizeof(aib));
        cin>>n;
        for(int i=1; i<=n; ++i)
        {
            cin>>a[i];
            Add(i,a[i]);
        }
        int q,q1=1,q2=1;
        int x,y,w,c;
        long long val;
        cin>>q;
        query1 v[q+1];
        query2 s[q+1];
        long long af[q+1];
        for(int i=1; i<=q; ++i)
        {
            cin>>c;
            if(c==1)
            {
                cin>>x>>y>>w;
                if(x>y) swap(x,y);
                v[q1].poz=q1;
                v[q1].x=x;
                v[q1].y=y;
                v[q1].k=w;
                q1++;
            }
            else
            {
                cin>>x>>val;
                s[q2].x=x;
                s[q2].val=val;
                s[q2].facut=false;
                q2++;
            }
        }
        int cur=1;
        s[0].facut=true;
        sort(v+1,v+q1,cmp);
        for(int i=1; i<q1; ++i)
        {
            for(int j=cur;j<=v[i].k;++j)
            if(s[j].facut==false)
            {
                Add(s[j].x,-a[s[j].x]);
                a[s[j].x]=s[j].val;
                Add(s[j].x,a[s[j].x]);
                s[j].facut=true;
            }
            cur=v[i].k;
            af[v[i].poz]=query(v[i].y)-query(v[i].x-1);
        }
        for(int i=1; i<q1; ++i)
            cout<<af[i]<<"\n";
    }
    return 0;
}

