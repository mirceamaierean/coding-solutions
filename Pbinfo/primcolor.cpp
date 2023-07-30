#include <fstream>
#include <bitset>
using namespace std;
bitset<50000001> culori;
ifstream cin("primcolor.in");
ofstream cout("primcolor.out");
int main()
{
    int n,cnt=2;
    cin>>n;
    if(n<=3) cout<<n;
    else
    {
        for(int i=2; i<=n/2; ++i)
            if(culori[i]==0)
            {
                for(int j=i+i; j<=n; j+=i)
                    culori[j]=1;
            }
        int j=n/2+1;
        for(int i=j; i<=n; ++i)
            if(culori[i]==0) ++cnt;
        cout<<cnt;
    }
    return 0;
}
