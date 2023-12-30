#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
ll n,i,key;
cin>>n;
ll a[n];
for(i=0;i<n;i++)
{
cin>>a[i];
}

cin>>key;
for(i=0;i<n;i++)
{
 if(a[i]==key)
 {
  cout<<i;

  return 0;
 }
}
cout<<-1;
return 0;
}
