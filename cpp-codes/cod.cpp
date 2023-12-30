#include<iostream>
using namespace std;
typedef long long ll;
int hcf(int a,int b)
{
    ll count;
    int flag;
    count=min(a,b);
    for(int i=count;i>=1;i--)
    {
    if(a%i==0 && b%i==0)
    {
        flag=i;
        return flag;
        break;
    }
   }
}
int lcm(int a,int b)
{
    int w=a*b;
    int l=hcf(a,b);
    return w/l;
}
int main()
{
ll x;
int flag=1;
cin>>x;
for(int i=1;i>=1;i++)
{
    for(int j=1;;j++)
    {
        if(lcm(i,j)==x)
        {
            ll w=max(i,j);
            if(w<flag)
            {
                cout<<i<<" "<<j;
            }
            flag=w;
            break;
        }
    }

}
return 0;
}
