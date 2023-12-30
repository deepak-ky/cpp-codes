#include<iostream>
#include<string.h>
using namespace std;
int main()
{
string s1,s2;
cin>>s1>>s2;
cout<<"String 1 : "<<s1<<endl;
cout<<"String 2 : "<<s2<<endl;
int w=(s1.compare(s2));
if(w==0)
{
    cout<<"Strings are equal";
}
else if(w!=0)
{
    cout<<"Strings are not equal";
}
s1.append(s2);
cout<<"\nAfter concatenating : "<<s1;
return 0;
}
