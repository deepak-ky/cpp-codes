#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
ll n,i,a;
ll count=0;
cin>>n;
for(i=5;n/i>=1;i=i*5)
{count=count+n/i;}
cout<<count;
return 0;
}
