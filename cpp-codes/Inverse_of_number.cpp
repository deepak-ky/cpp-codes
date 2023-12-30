#include<iostream>
#include<math.h>
using namespace std;
typedef long long int lli;
int main()
{
lli n;
cin>>n;
lli i=1;
lli r;
lli ans=0;
while(n>0)
{
   cout<<endl<<"i now : "<<i<<endl;
  r=n%10;
  if(r%2==0 || (r-1)==0)
  {
  cout<<"\nr now : "<<r<<endl;
  lli x=pow(10,(r-1));
  cout<<endl<<"x : "<<x<<endl;
  ans+=i*x;
  cout<<endl<<"ans : "<<ans<<endl;
  i++;
  n=n/10;
  cout<<"\n n now : "<<n<<endl;
  }
  else if(r%2!=0)
  {
  cout<<"\nr now : "<<r<<endl;
  lli x=pow(10,(r-1))+1;
  cout<<endl<<"x : "<<x<<endl;
  ans+=i*x;
  cout<<endl<<"ans : "<<ans<<endl;
  i++;
  n=n/10;
  cout<<"\n n now : "<<n<<endl;

  }

}
cout<<ans;
return 0;
}
