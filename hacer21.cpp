#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=1;
    int count1=n-2;
    int mid=(n/2)+1;
    int i1=0;
    int i2=0;
    int mid1,mid2;
    int i,j,k;
    for(i=1;i<=n;i++)
    {
      if(i==1 || i==n)
      {
          for(j=1;j<=n;j++)
         {
             cout<<"*"<<'\t';
         }
      }
     else if(i!=1 && i!=n)
      {
        mid1=mid-i1;
        mid2=mid+i1;
        if(i<mid)
        {
          i1++;
          i2++;
        }
        else if(i>=mid)
        {
          i1--;
          i2--;
        }
             for(j=1;j<=mid1-1;j++)
             {
               cout<<"*"<<'\t';
             }
             for(j=mid1;j<=mid2;j++)
             {
             cout<<" "<<'\t';
             }
             for(j=mid2+1;j<=n;j++)
             {
             cout<<"*"<<'\t';
             }
      }
    cout<<endl;
   }
return 0;
}
