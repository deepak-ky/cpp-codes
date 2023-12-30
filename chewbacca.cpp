#include<iostream>
#include<vector>
using namespace std;
const long long int size=100;
int main()
{
string s;
cin>>s;
s[0]='9'-s[0]+'0';
cout<<endl<<s;
return 0;
}
