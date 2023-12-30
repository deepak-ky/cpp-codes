#include<iostream>
#include<string.h>
using namespace std;
string once(string s3)
{
    int len,i,j,k;
    len=s3.length();
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(s3[i]!=s3[j])

            else if(s3[i]==s3[j])
            {
                s3[i]='\0';
                return once(s3);
            }
        }
    }
}
int main()
{
string s1,s2;
getline(cin,s1);
s2=once(s1);
cout<<s2;
return 0;
}
