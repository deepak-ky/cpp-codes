#include<bits/stdc++.h>
using namespace std;
class cal
{
 public:
 void power();
 void fact();
 void sqrtroot();
 void log();
 void ncr();
};
void cal :: power(void)
{
int a,b,i,j,k;
int f=1;
cout<<"Enter the numbers : ";
cin>>a>>b;
for(i=1;i<=b;i++)
{
 f=f*a;
}
cout<<"\nANS : "<<f;
}
void cal :: fact(void)
{
int a,b,i,j,k;
int f=1;
cout<<"Enter the number: ";
cin>>a;
for(i=a;i>=1;i--)
{
 f=f*i;
}
cout<<"\nANS : "<<f;
}
void cal :: sqrtroot(void)
{
int a,b,i,j,k;
int f=1;
cout<<"Enter the number: ";
cin>>a;
for(i=1;i<=a;i++)
{
 if(i*i==a)
 {
  f=i;
 }
}
cout<<"\nANS : "<<f;
}
void cal :: log(void)
{
int a,b,i,j,k,w;
int f=1;
cout<<"Enter the number: ";
cin>>a;
w=log10(a);
cout<<"\nANS : "<<w;
}
void cal :: ncr(void)
{
float n,i,r,ans;
cout<<"Enter n and r : ";
cin>>n>>r;
float w=n-r;
int n1=1;
int n2=1;
int r1=1;
for(i=n;i>=1;i--)
{
    n1=n1*i;
}
for(i=r;i>=1;i--)
{
    r1=r1*i;
}
for(i=w;i>=1;i--)
{
    n2=n2*i;
}
ans=(n1/(n2*r1));
cout<<"\nANS : "<<ans;
}
int main()
{
cal c1;
int ch;
char d;
label:
cout<<"1.POWER\n2.FACTORIAL\n3.SQUAREROOT\n4.LOG\n5.NCR";
cout<<"\nENTER YOUR CHOICE : ";
cin>>ch;
switch(ch)
{
    case 1 : c1.power();
             break;
    case 2 : c1.fact();
             break;
    case 3 : c1.sqrtroot();
            break;
    case 4 : c1.log();
             break;
    case 5 : c1.ncr();
             break;
}
cout<<"\nContinue (y/n) : ";
cin>>d;
if(d=='y')
{
    goto label;
}
else if(d=='n')
{
    exit(1);
}
return 0;
}

























