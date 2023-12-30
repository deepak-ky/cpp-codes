#include<iostream>
using namespace std;
typedef long long int lli;
void prime_sieve(lli p[])
{
  for(lli i=3;i<=1000000;i+=2)
  {
    p[i]=1;
  }

  for(lli i=3;i<1000000;i+=2)
  {


    if(p[i]==1)
    {

      for(lli j=(i*i);j<1000000;j=j+i)
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
lli n;
n = 10000;
lli p[100005]={0};
prime_sieve(p);
for(lli i=0;i<=n;i++)
{
    if(p[i]==1)
    {
        cout<<i<<endl;
    }
}
return 0;
}
