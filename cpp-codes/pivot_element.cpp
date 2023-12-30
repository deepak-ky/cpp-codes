#include<iostream>
using namespace std;
int  find_key(int a[],int n,int key)
{
    int s=0;
    int e=n-1;
    int mid=(s+e)/2;
    while(s<=e)
    {
      if(a[mid]==key)
      {
          return mid;
      }
      else if(a[s]<=a[mid])
      {
         if(key>=a[s] && key<=a[mid])
         {
             e=mid-1;
         }
         else
         {
             s=mid+1;
         }
      }
      else if(a[s]>=a[e])
      {
         if(key>=a[mid] && key<=a[e])
         {
             s=mid+1;
         }
         else
         {
             e=mid-1;
         }
      }
     mid=(s+e)/2;
    }
return -1;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cout<<"\nPosition of element is : ";
    cin>>key;
    int a1;
    a1=find_key(a,n,key);
    cout<<a1;
 return 0;
}


