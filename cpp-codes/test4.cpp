#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{cin>>a[i];}
for(int i=0;i<n;i++)
{cout<<a[i]<<" ";}
swap(a[0],a[3]);
cout<<endl;
for(int i=0;i<n;i++)
{cout<<a[i]<<" ";}
return 0;









}
