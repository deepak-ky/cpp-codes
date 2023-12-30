#include<iostream>
using namespace std;
int main()
{
float i,j,k,l,a,f,count;
cin>>a;
f=1;
for(j=1;j<=5;j++)
{
    for(i=1;i<=j;i++)
    {
     f=f*10;
     if(f==a)
     {
        cout<<"yeh";
     }
     else if(f!=a)
     {
        continue;
     }
    }
}
return 0;
}
