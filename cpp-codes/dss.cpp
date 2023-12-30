#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
string s;
cin>>s;
int fis;
int sec;
int w=s.length();
char ch = '1';
char ch1 = '0';
for(int i=0;i<w;i++)
{
    if(s[i]==ch)
    {
        fis=i;
        break;
    }
}
for(int i=0;i<w;i++)
{
    if(s[i]==ch)
    {
        sec=i;
    }
}
int count=0;
if(fis!=ch1 && sec!=ch1)
{
for(int i=fis;i<=sec;i++)
{
    if(s[i]==ch1)
    {
        count++;
    }
}
cout<<count<<endl;
}
else
cout<<count<<endl;
}

return 0;

}
