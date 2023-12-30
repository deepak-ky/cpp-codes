#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
 {
	string str;
	cin>>str;
	int count=0;
	int flag=1;
    int w=str.length();
    cout<<"\nstring length is : "<<w<<endl;
	stack<char> s1;
	for(int i=0;i<w;i++)
	{

      if(str[i]=='[' || str[i]=='{' || str[i]=='(')
        {
            s1.push(str[i]);
            char ch=s1.top();
            cout<<"\nTop now : "<<ch<<endl;
        }
	  else if((str[i]==']' || str[i]=='}' || str[i]==')') && flag!=2 && (s1.empty()!=1))
	   {
	       char p=str[i];
	       char ch=s1.top();
	       switch(p)
	       {
	           case ')' : if(ch=='(')
	                       {
	                           s1.pop();
	                           count++;
	                           break;
	                       }
	                       else flag=2;
	                       break;
	          case ']' : if(ch=='[')
	                       {
	                           s1.pop();
	                           count++;
	                           break;
	                       }
	                       else flag=2;
	                       break;
	          case '}' : if(ch=='{')
	                       {
	                           s1.pop();
	                           count++;
	                           break;
	                       }
	                       else flag=2;
	                       break;
	       }
	   }
else if((str[i]==']' || str[i]=='}' || str[i]==')') && flag!=2 && (s1.empty()==1))
{
    flag=2;
    break;
}



	}
	if(flag==1 && (s1.empty()==1))
	{cout<<"YES with count : "<<count;}
	else cout<<-1;
	return 0;
}
