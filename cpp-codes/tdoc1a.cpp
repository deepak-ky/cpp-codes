#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
ll a,b,i;
ll count;
cin>>a>>b;
count=min(a,b);
for(i=count;i>=1;i--)
{
    if(a%i==0 && b%i==0)
    {
        cout<<i;
        break;
    }
}
return 0;
}
