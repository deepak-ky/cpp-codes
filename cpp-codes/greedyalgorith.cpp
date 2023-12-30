#include<iostream>
using namespace std;
int main()
{
int n,i,j,k,m,p,temp,x,time;
int currenttime=0;
int numberofthings=0;
cout<<"enter the maximum possible time : ";
cin>>time;
cout<<"enter the number of integers : ";
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

}
cout<<endl<<"Sorted array : ";
for(p=0;p<n;p++)
 {
   cout<<a[p];
}
for(i=0;i<n;i++)
{
    currenttime=currenttime+a[i];
    if(currenttime>time)
        break;
    numberofthings++;
}
cout<<endl<<"Maximium of possible things : "<<endl<<numberofthings;
return 0;
}

