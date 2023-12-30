#include<iostream>
#include<string.h>
using namespace std;
int main()
{
 string str;
 cin>>str;
 int flag=1;
 int w=str.length();
 cout<<"\nThe string length is : "<<w<<endl;
 stack<char> s1;
 for(int i=0;i<w;i++)
 {
     if(str[i]=='(')
     {
        s1.push(str[i]);
        char ch=s1.top();
        cout<<"Top now : "<<ch<<endl;
    }
    else if((str[i]==')') && flag!=2 && (s1.empty!=1))
    {
        char p=str[i];
        char ch=s1.top();
        if(ch=='(')
        {
            s1.pop();
        }
        else
        flag=2;
        break;
    }
     else if((str[i]==')') && flag!=2 && (s1.empty==1))
     {
        flag=2;
        break;
     }
 }

	if(flag==1 && (s1.empty()==1))
	{cout<<"YES";}
	else cout<<"NO";
	return 0;
}
