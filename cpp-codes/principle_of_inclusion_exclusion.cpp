#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
typedef long long int lli;
int main()
{
    lli t;
    cin>>t;
    lli primes[]={2,3,5,7,11,13,17,19};
    while(t--)
    {
        lli n;
        cin>>n;
        lli subsets=(1<<8)-1;
        lli ans=0;
        for(lli i=1;i<=subsets;i++)
        {
            lli denom=1;
            lli setbits=__builtin_popcount(i);
            for(lli j=0;j<=7;j++)
            {
                if(i&(1<<j))
                {
                    denom=denom*primes[j];
                }
            }
            if(setbits&1)
            {
                ans+=n/denom;
            }
            else
            {
                ans-=n/denom;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
