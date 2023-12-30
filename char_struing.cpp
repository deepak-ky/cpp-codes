#include<iostream>
using namespace std;
#include<cstring>
#include<algorithm>
bool compare(string a,string b)
 {
     return b.length()<a.length();
 }
int main()
{
string s[] = {"Applr","zuvava","pineapple"};
sort(s,s+3,compare);
for(int i=0;i<3;i++)
{


cout<<s[i]<<",";
}


return 0;
}
