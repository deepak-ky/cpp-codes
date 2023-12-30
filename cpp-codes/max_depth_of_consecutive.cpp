#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {


 string str;
 cin>>str;
 int flag=1;
 int count=1;
 int maxcnt=0;
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
        count++;
        maxcnt=max(maxcnt,count);
    }
    else if((str[i]==')') && (flag!=2) && (s1.empty()!=1))
    {
      char p=str[i];
      char ch=s1.top();
	       switch(p)
	       {
	           case ')' : if(ch=='(')
	                       {
	                           s1.pop();
	                           count--;
	                           break;
	                       }
	                       else flag=2;
	                       break;

	       }
    }
     else if((str[i]==')') && flag!=2 && (s1.empty()==1))
     {
        flag=2;
        break;
     }
 }

	if(flag==1 && (s1.empty()==1))
	{cout<<maxcnt-1<<endl;}
	else cout<<-1<<endl;
}
	return 0;
}
