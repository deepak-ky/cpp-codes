#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int toint(string w,int lenn)
{
  if((lenn)==0)
  {
      return (w[lenn]-'0');
  }
  int prevans=toint(w,lenn-1);
  int i=w[lenn]-'0';
  return prevans*10+i;
}
int main()
{
  string w;
  cin>>w;
  int len=w.length();
//  cout<<toint(w);
//int ans=0;
//for(int i=0;i<len;i++)
//{
//    int a=w[i]-'0';
//    ans=ans+a;
//    if(i!=len-1)
//    {
//        ans=ans*10;
//    }
//}
//  cout<<"\nans here:"<<ans;
  cout<<toint(w,(len-1));
return 0;
}


