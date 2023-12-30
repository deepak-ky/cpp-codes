#include<iostream>
#include<string>
using namespace std;
int main()
{
string s;
cin>>s;
int i=0;
int alphabet[26]={0};
int j;
while(s[i]!='\0')
{
  j=s[i]-'a';
  alphabet[j]++;
  i++;
}
for(int i=0;i<25;i++)
{
 if(alphabet[i]!=0)
 {
 cout<<char(i+'a')<<alphabet[i];
 }
}
return 0;
}
