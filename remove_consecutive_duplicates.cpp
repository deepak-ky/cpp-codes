#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
 char a[100];
 cin>>a;
 int len=strlen(a);
 if(len!=1 || len!=0)
 {
     int prev=0;
     for(int curr=1;curr<len;curr++)
     {
         if(a[prev]!=a[curr])
         {
             prev++;
             a[prev]=a[curr];
         }
     }
     a[prev+1]='\0';
 }
cout<<endl<<a;
return 0;
}
