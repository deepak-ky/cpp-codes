#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int x[n];
int y[n];
int p[n];
int m,c;
cin>>m>>c;
int sum1=0;
int sum2=0;
int i,j,k;
for(i=0,j=0,k=0;i<n,j<n,k<n;i++,j++,k++)
{cin>>x[i]>>y[j]>>p[k];}
for(i=0,j=0,k=0;i<n,j<n,k<n;i++,j++,k++)
{
    int w=m*x[i]+c;
    if(w<y[j])
    {
        sum1=sum1+p[k];
    }
    if(w>y[j])
    {
        sum2=sum2+p[k];
    }
}
if(sum1>=sum2)
cout<<sum1;
else;
cout<<sum2;
return 0;
}
