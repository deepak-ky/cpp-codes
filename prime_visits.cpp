#include<iostream>
using namespace std;
typedef long long int lli;
void prime_sieve(lli p[])
{
  for(lli i=3;i<=100000;i+=2)
  {
    p[i]=1;
  }

  for(lli i=3;i<=100000;i+=2)
  {


    if(p[i]==1)
    {

      for(lli j=(i*i);j<=100000;j=j+i)
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
lli c[100005]={0};
for(lli i=1;i<=100000;i++)
{
    c[i]=c[i-1]+p[i];
}
int q;
cin>>q;
while(q--)
{
    lli a,b;
    cin>>a>>b;
    cout<<(c[b]-c[a-1])<<endl;
}
return 0;
}
