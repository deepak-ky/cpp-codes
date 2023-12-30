#include<iostream>
using namespace std;
typedef long long ll;
ll printfibo(ll a)
{
 if(a==0 || a==1)
  {
    return a;
  }
 return printfibo(a-1)+printfibo(a-2);
}
int main()
{
ll n,d;
cin>>n;
ll j=0;
ll a1[10000];
for(int i=0;;i++)
{    if(printfibo(i)>n)
      {
          cout<<"No";
          break;
      }
   else if(printfibo(i)==n)
     {
       cout<<"Yes";
       break;
     }
}
return 0;
}
