#include<iostream>
#include<string.h>
using namespace std;
int main()
{
string s1,s2;
getline(cin,s1);
getline(cin,s2);
int l1=s1.length();
int l2=s2.length();
int w=(s1.compare(s2));
if(w==0)
{
    cout<<-1;
}
else{
int maxx=max(l1,l2);
cout<<maxx;
}
return 0;
}
