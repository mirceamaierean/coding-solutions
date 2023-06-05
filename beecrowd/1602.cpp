#include <iostream>
#include <bitset>
#define NMAX 2000001
using namespace std;
int shiper[NMAX],ndiv[NMAX];
int main()
{
    int i,j;
    bitset <NMAX+1> ciur;
    ciur.set();/// pun 1 peste tot in ciur

    for(int i=2; i<=NMAX; ++i)
        if(ciur[i]==1)
        {
            shiper[i]=shiper[i-1]+1;/// numara cate numere hyperprime avem pana la i

            for(j=i+i; j<=NMAX; j=j+i)
            {
                ciur[j]=0;
                int p=0;
                int jj=j;
                while(jj%i==0)
                {
                    p++;
                    jj=jj/i;
                }
                if(ndiv[j]==0) ndiv[j]=p+1;
                else ndiv[j]=ndiv[j]*(p+1);

            }
        }

        else if(ciur[ndiv[i]]==1) shiper[i]=shiper[i-1]+1;
        else shiper[i]=shiper[i-1];




    int n;
    while(cin>>n)

        cout<<shiper[n]<<endl;

    return 0;
}
