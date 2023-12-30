#include<iostream>
using namespace std;
int main()
{
char a[10];
int i,j,k,l,m,n,o,p;
int strlength=0;
cout<<"Enter your string : ";
cin>>a;
cout<<"Original string : "<<a<<endl;
for(i=0;a[i]!='\0';i++)
{
 strlength++;
}
cout<<"Reversed string : ";
for(j=strlength;j!=-1;j--)
{
    cout<<a[j];
}
return 0;
}
