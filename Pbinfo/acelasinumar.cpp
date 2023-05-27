#include <iostream>
using namespace std;
int main()
{
    long long n,suma=0,a,k;
    cin>>n>>k;
    for(int i=1;i<=k;++i)
    {
        cin>>a;
        suma+=a;
    }
    if(suma+n==n) cout<<"DA";
    else cout<<"NU";
    return 0;
}
