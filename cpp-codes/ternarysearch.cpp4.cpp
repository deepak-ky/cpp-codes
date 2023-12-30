#include<iostream>
using namespace std;
int ternarysearch(int arr[],int l,int h,int x);
int main()
{
int i,j,k,n,m,h,p,w;
cin>>n;
int a[n];
for(i=0;i<n;i++)
{
    cin>>a[n];

}
cout<<"enter the element to be searched : ";
cin>>p;
w=ternarysearch(a,0,n-1,p);
cout<<endl<<endl<<"the element to be found was : "<<w;
return 0;
}
int ternarysearch(int arr[],int l,int h,int x)
{
    int mid1,mid2;
    if(l<=h)
     mid1=l+(h-l)/3;
    mid2=h-(h-l)/3;
    if(arr[mid1]==x)
        return mid1;
    if(arr[mid2]==x)
        return mid2;
    if(x<arr[mid1])
        return ternarysearch(arr,l,mid1-1,x);
     if(x>arr[mid2])
        return ternarysearch(arr,mid2+1,h,x);
     else ternarysearch(arr,mid1+1,mid2-1,x);
 return -1;
}




























