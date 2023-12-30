#include<iostream>
using namespace std;
typedef long long int lln;
lln rev(lln n)
{
lln r;
lln ans=0;
while(n!=0)
{
r=n%10;
ans=ans*10+r;
n=n/10;
}

return ans;
}
int main()
{
    lln t;
    cin>>t;
    while(t--)
    {
   lln n,n1;
  cin>>n>>n1;
lln w=rev(n)+rev(n1);
cout<<rev(w);

}
return 0;
}
