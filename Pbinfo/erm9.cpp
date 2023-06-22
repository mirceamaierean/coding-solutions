#include <iostream>
#include <string.h>
using namespace std;
string baza,exp;
unsigned long long b,e,cor=0,n,mod=9,nr=1,p;
unsigned long long Mod1()
{
    unsigned long long R=0;
    for (int i=0; i<exp.size(); ++i)
        R=(10*R%6+exp[i]-48)%6;
    return R;
}
unsigned long long Mod2()
{
    unsigned long long R=0;
    for (int i=0; i<baza.size(); ++i)
        R=(10*R%mod+baza[i]-48)%mod;
    return R;
}
int main ()
{
    cin>>baza;
    cin>>exp;
    n=Mod2();
    if(n==3||n==6||n==9)
    {
        if(exp.size()==1&&exp[0]=='1') cout<<n<<"\n";
        else cout<<"9\n";
        return 0;
    }
    p=Mod1();
    while(p)
    {
        if(p%2==1)
        {
            nr=(nr*n)%mod;
            p--;
        }
        else
        {
            n=(n*n)%mod;
            p/=2;
        }
    }
    if(nr) cout<<nr<<"\n";
    else cout<<"9\n";
    return 0;
}
