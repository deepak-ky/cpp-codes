#include<iostream>
using namespace std;
int main()
{
int i,k,l,n;
int count=1;
int j=0;
i=1;
cin>>n;
while(i<=n)
{
 while(j!=i)
 {
  cout<<count;
  count++;
 }
 i++;
cout<<endl;
}
return 0;
}
