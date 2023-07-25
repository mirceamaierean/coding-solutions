#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<unsigned long long> vect;
ifstream cin("parap.in");
ofstream cout("parap.out");
void descopunere(unsigned long long nr,int i)
{
    int f[10]={0};
    unsigned long long a=1;
    while(nr)
    {
        ++f[nr%10];
        nr/=10;
    }
    for(int j=0; j<=9; ++j)
       a=a*10+f[j]%2;
    vect.push_back(a);
}
int main()
{
    unsigned long long nr,cnt=0;
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>nr;
        descopunere(nr,i);
    }
    sort(vect.begin(),vect.end());
    for(int i=0; i<n-1; ++i)
    {
        unsigned long long apar=1;
        while(vect[i]==vect[i+1]&&i<n)
        {
            ++i;
            ++apar;
        }
        cnt+=apar*(apar-1)/2;
    }
    cout<<cnt;
    return 0;
}
