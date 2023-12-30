#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
string a,b,c;
cin>>a>>b>>c;
int w=a.length();
int flag=0;
int swaps=0;
int i,j,k;
for(i=0,j=0,k=0;k<w;i++,j++,k++)
 {
   if(a[i]!=b[j])
    {
      if(a[i]==c[k])
       {
       swap(b[j],c[k]);
       swaps++;
       }
      else if(b[j]==c[k])
       {
       swap(a[i],c[k]);
       swaps++;
       }
       else if(a[i]!=c[k] && b[j]!=c[k])
       {
           flag=1;
           break;
       }
    }
 }
 int l=a.compare(b);
if(flag==0 && swaps==w && l==0)
{
    cout<<"YES"<<endl;
}
else cout<<"NO"<<endl;
}
return 0;
}
