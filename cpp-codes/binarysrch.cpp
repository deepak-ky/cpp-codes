#include<iostream>
using namespace std;
int main()
{
int n,j,i,k,l,low,high,mid,num,q,e,f;


cin>>n;
int a[n],b[n];
for(i=0;i<n;i++)
{
cout<<"enter the number"<<i+1<<" : ";
cin>>a[i];
}
low=0;
high=n-1;
mid=((low+high)/2);
cout<<"how many times do you want to find a number";
cin>>q;



cout<<endl<<"enter the number to be searched";
cin>>num;
while(low<=high)
{
    if(a[mid]<num)
    {
      low=mid+1;
    }
    else if(a[mid]==num)
    {
      cout<<"element found at : "<<mid+1;
      b[e]=a[mid];
      e++;
      break;
    }
    else if(a[mid]>num)
    {
      high=mid-1;
    }
    mid=((low+high)/2);
}
if(low>high)
{
    cout<<"not found";
}
q--;
}
cout<<endl<<endl;
for(int f=0;f<e;f++)
{
    cout<<b[f];
}
return 0;
}
