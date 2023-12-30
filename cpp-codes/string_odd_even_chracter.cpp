#include<iostream>
#include<string.h>
using namespace std;
int main()
{
string s;
cin>>s;
int w=s.length();
cout<<"\nS : "<<s;
for(int i=0;i<w;i++)
{
    if(i%2==0)
    {
        s[i]++;
    }
    else s[i]--;
}
cout<<"\nS : "<<s;
return 0;
}
