#include<iostream>
using namespace std;
float binsquareroot(int n,int p)
{
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    float ans=-1;
    while(low<=high)
    {
      if((mid*mid)==n)
      {
          ans=mid;
          break;
     }
      else if((mid*mid)>n)
      {
         high=mid-1;
      }
       else if((mid*mid)<n)
      {
         low=mid+1;
         ans=mid;
      }
       mid=(low+high)/2;
    }
    float inc=0.1;
    for(int i=0;i<p;i++)
    {
        while((ans*ans)<=n)
        {
            ans=ans+inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
return ans;
}
int main()
{
    int n,p;
    cin>>n>>p;
    float a1;
   a1=binsquareroot(n,p);
    cout<<a1;
 return 0;
}

