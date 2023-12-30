#include<iostream>
#include<string>
using namespace std;
int main()
{
string s;
cin>>s;
int i=0;
while(s[i]!='\0')
{
  char ch=s[i];
  cout<<s[i];
  int k=i+1;
  int j=1;
  while(s[k]==ch)
  {
      j++;
      k++;
  }
  cout<<j;
  i=i+j;
}
return 0;
}
