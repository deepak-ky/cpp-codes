#include<iostream>
using namespace std;
typedef long long int lli;
void prime_sieve(lli p[])
{
  for(lli i=3;i<=100000;i+=2)
  {
    p[i]=1;
  }

  for(lli i=3;i<100000;i+=2)
  {


    if(p[i]==1)
    {

      for(lli j=(i*i);j<100000;j=j+i)
      {

        p[j]=0;
      }

    }
   }

p[2]=1;

p[1]=p[0]=0;


}
int main()
{
lli p[100005]={0};
prime_sieve(p);
lli ans[100005];
ans[0]=1;
ans[1]=2;
ans[2]=3;
ans[3]=4;
ans[4]=5;
lli i=5;
lli val=6;
lli n;
cin>>n;
while(i<=n)
{
    if(p[val]==0)
    {
        ans[i]=val;
        val++;
        i++;
    }
    else val++;
}
for(int i=0;i<=n;i++)
{
    cout<<ans[i]<<endl;
}
//lli t;
//cin>>t;
//while(t--)
//{
//  lli n;
//  cin>>n;
//
//
//
//
//}
return 0;
}
