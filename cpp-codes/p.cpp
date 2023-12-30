#include<bits/stdc++.h>
using namespace std;
int main()
{
char a[100],b[100],c[100];
int i,g,j,k,l,m,n;
int flag=0;
int sla,slb;
sla=0;
slb=0;
cout<<"Enter the string : ";
cin>>a;
cout<<"String : "<<a<<"\n";
for(m=0;a[m]!='\0';m++)
{
    sla++;
}
for(i=0,j=sla-1;a[i]!='\0',j!=-1;i++,j--)
{
   if(a[i]==a[j])
   {
    flag=1;

   }
   else flag=2;
}
if(flag==1)
{
    cout<<"Palindrome";

}
else if(flag==2)
{
    cout<<"Not a Palindrome";

}
return 0;
}
