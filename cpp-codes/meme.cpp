#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int tc=0;
    cin>>tc;
    long a,b;
    int count=0;
    long bcopy=0;
    long ans;
    while(tc!=0)
    {
        ans=0;
        count=0;
        cin>>a>>b;
        bcopy=b;
        while(b>0)
        {
            count++;
            b=b/10;
        }
        double x=pow(10,count)-1;
        if(bcopy==x)
        {
            ans=a*count;
        }
        else if(bcopy<x)
        {
            ans=a*(count-1);
        }
        cout<<ans<<endl;
        tc--;
    }
    return 0;
}
