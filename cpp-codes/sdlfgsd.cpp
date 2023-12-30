#include<iostream>
#include<math.h>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
long long int  fact(long long int  a)
{
long long int  i;
long long int  j=1;
for(i=a;i>=1;i--)
{
j=j*i;
}
return j;
}
int main()
{
long long int  n,w;
cin>>n;
w=fact(n);
cout<<w;
return 0;
}
