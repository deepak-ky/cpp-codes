#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
float v,i;
int flag;
float a,b,c,d,e,f;
cin>>a>>b>>c>>d>>e>>f;
float a1,b1,c1,d1,e1;
float res;
for(i=0.0001;i<=0.9999;i+=0.0001)
{
    a1=(a*pow(2,(-i)));
    b1=(b*sin(i));
    c1=(c*cos(i));
    d1=(d*tan(i));
    e1=(e*pow(i,2));
    res=a1+b1+c1+d1+e1+f;
    if(res==0)
    {
       flag=1;
       v=i;
       break;
    }
    else flag=-1;
}
cout<<endl<<flag;
return 0;
}
