#include<iostream>
using namespace std;
int main()
{
int i,j,k,l,n;
cout<<"Enter the size of the array : ";
cin>>n;
int a[n];
for(i=0;i<n;i++)
{
cout<<"Enter the element "<<i+1<<" : ";
cin>>a[i];
}
cout<<"\nReversed array :";
for(i=n-1;i>=0;i--)
{
cout<<" "<<a[i];
}
return 0;
}
