#include<iostream>
using namespace std;
typedef long long int lli;
int main()
{
lli t;
cin>>t;
lli a,b;
while(t--)
{
cin>>a>>b;
if(a%b==0)
{
    cout<<0<<endl;
}
else{
lli i=a/b;
cout<<(b*(i+1))-a<<endl;
}
}
return 0;
}
