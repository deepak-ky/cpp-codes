#include<iostream>
using namespace std;
int binsrch(int a[],int n1,int n)
{
int low=0;
int high=n-1;
int mid;
mid=((low+high)/2);
while(low<=high)
{
 if(a[mid]<n1)
 {
  low=mid+1;
 }
else if(a[mid]>n1)
 {
 high=mid-1;
 }
else if(a[mid]==n1)
 {
 return mid+1;
 }
mid=((low+high)/2);
}
if(low>high)
{
return -5;
}
}

int main()
{
cout<<"Enter the number of elements : ";
int n;
cin>>n;
int a[n];
cout<<"\nEnter the elements : \n";
for(int i=0;i<n;i++)
{
cout<<"Enter element "<<i+1<<" : ";
cin>>a[i];

}
cout<<"Enter the element to be searched for : ";
int n1;
cin>>n1;
int w;
w=binsrch(a,n1,n);
if(w==-5)
{
cout<<"Element is not present";
}
else
{
cout<<"Element is present\n";
cout<<"At location : "<<w;
}
return 0;
}
