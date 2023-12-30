#include<iostream>
using namespace std;
int main()
{
int n,i,j,k,m,p,temp,x;
cin>>n;
int a[n];
for(p=0;p<n;p++)
 {
   cout<<"Enter the number "<<p+1<<" : ";
   cin>>a[p];
}
cout<<endl<<"Unsorted array : ";
for(p=0;p<n;p++)
 {
   cout<<a[p];
}
cout<<endl<<"Enter the number of iterations : ";
cin>>x;
for(i=0;i<n;i++)
{
    for(j=i+1;j<n;j++)
    {
        if(a[i]>a[j] && i<=x)
        {
         temp=a[j];
         a[j]=a[i];
         a[i]=temp;
        }
    }
    cout<<endl<<a[i]<<endl;
}
cout<<endl<<"Sorted array : ";
for(p=0;p<n;p++)
 {
   cout<<a[p];
}
return 0;
}
