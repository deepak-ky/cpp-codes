#include<iostream>
using namespace std;
typedef long long int lli;
void prime_sieve(lli p[])
{
  for(lli i=3;i<=INT_MAX;i+=2)
  {
    p[i]=1;
  }

  for(lli i=3;i<=INT_MAX;i+=2)
  {


    if(p[i]==1)
    {

      for(lli j=(i*i);j<=INT_MAX;j=j+i)
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

lli p[INT_MAX]={0};
prime_sieve(p);
lli c[100005];
lli j=0;
for(lli i=0;i<=100000;i++)
{
    if(p[i]==1)
    {
        c[j]=i;
        j++;
    }
}
lli q;
cin>>q;
cout<<c[q-1];
return 0;
}
