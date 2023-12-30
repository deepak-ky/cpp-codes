#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
int main()
{
ll a;
cin>>a;
if(a==1 || a==2)
{
cout<<-1;
}
else if(a%2==0)
{
    ll a1,b,c,d,c1,d1,ans;
    a1=pow(a,2);
    b=a/2;
    c=(pow(b,2)-1);
    d=pow(c,2);
    c1=(pow(b,2)+1);
    d1=pow(c1,2);
    ans=a1+d;
    if(ans==d1)
    {
        cout<<c<<" "<<c1;
    }
}
else if(a%2!=0)
{
    ll a1,b,c,d,c1,d1,ans;
    a1=pow(a,2);
    b=a/2;
    c=(pow(b,2)-1);
    d=pow(c,2);
    c1=(pow(b,2)+1);
    d1=pow(c1,2);
    ans=a1+d;
    if(ans==d1)
    {
        cout<<c<<" "<<c1;
    }
}
return 0;
}
