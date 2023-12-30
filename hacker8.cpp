#include<iostream>
using namespace std;
void printheretothere(int a,int b)
{
    int j;
    for(j=a;j<=b;j++)
    {
       cout<<j<<"\t";
    }
}
int main()
{
int i,j,k,l,n;
int thiscnt=1;
cin>>n;
for(i=0;i<n;i++)
{
   printheretothere(thiscnt,thiscnt+i);
  thiscnt=thiscnt+i+1;
  cout<<endl;
}
return 0;
}
