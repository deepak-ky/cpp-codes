#include<iostream>
#include<string>
using namespace std;
int main()
{
   string s;
   cin>>s;
   int len=s.length();
   int i=0;
   while(s[i]!='\0')
   {
     if(s[i]>='A' && s[i]<='Z')
	 {
       cout<<"\nI now : "<<i<<endl;
       int j=1;
       int k=i+1;
       cout<<"\nK now : "<<k<<endl;
       while(s[k]>='a' && s[k]<='z')
       {
           j++;
           k++;
       }
       cout<<"\nJ now : "<<j<<endl;
       string r=s.substr(i,j);
       cout<<endl<<r<<endl;
       i=i+j;
       cout<<"\nI now : "<<i<<endl;
    }
    else
    {
        i++;
    }



  }
    return 0;
}
