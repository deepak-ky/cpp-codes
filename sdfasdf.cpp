#include<iostream>
using namespace std;
char checkcase(char s)
{
if(s>='a' && s<='z')
{ return 'L';}
else if(s>='A' && s<='Z')
{ return 'U';}
else
return 'I';
}
int main()
{
char ch,t;
cin>>ch;
t=checkcase(ch);
cout<<t;
return 0;
}
