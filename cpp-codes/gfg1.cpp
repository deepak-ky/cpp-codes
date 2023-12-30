#include<bits/stdc++.h>
using namespace std;
int main()
{
int r;
int n;
cout<<"Enter the number of integers : ";
cin>>n;
int a[n];
cout<<"Binary expansion of n: ";
while(n!=0)
{
r=n%2;
n=n/2;
cout<<r;
}














return 0;
}
