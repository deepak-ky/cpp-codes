#include<iostream>
#include<math.h>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
double int fact(double int a)
{
 double int d;
 double int e=1;
 for(d=a;d>=1;d--)
 {
     e=e*d;
 }
 return e;
}
int main()
{
double int n,w,r,h,j,i,k;
cin>>n;
j=fact(n);
k=n*2;
w =fact(k);
r=fact(n+1);
i=j*r;
h=w/i;
cout<<h;
return 0;
}
