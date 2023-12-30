#include<iostream>
#include<string.h>
using namespace std;
int checkinit(string s1,string s2)
{
   int len1=s1.length();
   int len2=s2.length();
   for(int i=0;i<=len1-len2;i++)
   {
       int j;
       for( j=0;j<len2;j++)
       {
           if(s1[i+j]!=s2[j])
            break;
            if((j+1)==len2)
            return i;
      }
   }
   return -1;
}
int main()
{
string s1,s2;
int flag=0;
cin>>s1>>s2;
int count=1;
int len1=s1.length();
int len2=s2.length();
cout<<"String 1 : "<<s1<<endl;
cout<<"String 2 : "<<s2<<endl;
while(checkinit(s1,s2)<0)
{

    s1=s1+s1;
    count++;
    flag=0;
        int len3=s1.length();
    if(len3>len2)
        cout<<"-1";
        flag=1;
    break;
}
if(flag==0)
cout<<endl<<count;
return 0;
}
