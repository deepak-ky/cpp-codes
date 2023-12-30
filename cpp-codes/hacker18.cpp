#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool iscorrect(string exp)
{
 stack<char> stack;
 for(int i=0;i<exp.length();i++)
 {
     if(exp[i]!=')')
     {
         stack.push(exp[i]);
     }
     else
     {


         if(stack.top()=='(')
            {
                return true;
            }
       while(stack.top()!='(')
       {
           stack.pop();
       }
       stack.pop();
     }

 }

 return false;
}
int main()
{
string exp;
cin>>exp;
if(iscorrect(exp))
{
cout<<"True";
}
else cout<<"False";
return 0;
}
