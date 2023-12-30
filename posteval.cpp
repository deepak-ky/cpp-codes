#include<iostream>
#include<string>
#include<stack>
using namespace std;
int postfix(string s)
{
  int len=s.length();
  stack<int> st;
  for(int i=0;i<len;i++)
  {
   if(s[i]>='0' && s[i]<='9')
    {
		st.push(s[i]-'0');
		int tp=st.top();
	}
	else
	{
       if(s[i]=='+')
	   {
	       int w=0;
		   int top=st.top();
		   w=w+top;
		   st.pop();
		   int top1=st.top();
		   w=w+top1;
		   st.pop();
		   st.push(w);
	   }
	   else if(s[i]=='-')
	   {
	       int w=0;
		   int top=st.top();
		   w=w+top;
		   st.pop();
		   int top1=st.top();
		   w=w-top1;
		   st.pop();
		   st.push(-w);
	   }
	   else if(s[i]=='*')
	   {
	       int w=1;
		   int top=st.top();
		   w=w*top;
		   st.pop();
		   int top1=st.top();
		   w=w*top1;
		   st.pop();
		   st.push(w);
	   }
	   else if(s[i]=='/')
	   {
	       int w=1;
		   int top=st.top();
		   w=w*top;
		   st.pop();
		   int top1=st.top();
		   w=top1/w;
		   st.pop();
		   st.push(w);
	   }
  	}
  }
  return st.top();
}
int main() {
	string s;
	cin>>s;
	cout<<postfix(s);
	return 0;
}
