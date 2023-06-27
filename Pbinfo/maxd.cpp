#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
int prim(int n,int d)
{
    for(int i=d;i<=sqrt(n);++i)
    if(n%i==0) return i;
    return n;
}
ifstream cin("maxd.in");
ofstream cout("maxd.out");
int main()
{
    int a,b;
    cin>>a>>b;
    int cnt=0,dmax=0,max=0;
    for(int i=a;i<=b;++i)
    {
        int ndiv=1,cop=i,d=prim(i,2),p=0;
        while(cop>1)
        {
            p=0;
            while(cop%d==0)
            {
                cop/=d;
                ++p;
            }
            ndiv*=(p+1);
            d=prim(cop,d);
        }
        if(ndiv>dmax)
        {
            max=i;
            cnt=1;
            dmax=ndiv;
        }
        else if(ndiv==dmax) ++cnt;
    }
    cout<<max<<" "<<dmax<<" "<<cnt;
    return 0;
}
