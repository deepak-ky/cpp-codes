#include<iostream>
using namespace std;
typedef long long int lli;
lli fact(lli n)
{
if(n==1 || n==0)
 {return 1;}
 else return n*fact(n-1);
}
int main()
{
lli t;
cin>>t;
lli k;
cin>>k;
lli a[t];
lli a1[t];
lli b[t];
lli b1[t];
for(lli i=0;i<t;i++)
{
     cin>>a1[i]>>b1[i];
     if(a1[i]>=1 && b1[i]>=1 && b1[i]>=a1[i])
     {
         a[i]=a1[i];
         b[i]=b1[i];
     }
     else
        continue;
}
for(lli i=0;i<t;i++)
{
    lli ans=0;
    for(lli j=a[i];j<=b[i];j++)
    {
       if(j<k)
       {
           ans=ans+1;
       }
       else if(j==k)
       {
           ans=ans+2;
       }
       else if(j>k)
       {
           ans=ans+1;
           if(j%k==0)
           {
               ans=ans+1;
           }
          lli w=fact(j-1)/fact(j-k);
          ans=ans+w;

       }
    }
    cout<<(ans%1000000007)<<endl;
}
return 0;
}
