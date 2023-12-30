#include<iostream>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
 cin>>arr[i];
}
int inc[n],dec[n];
int i,mmax;
inc[0]=1;
dec[n-1]=1;
for(int i=1;i<n;i++)
{
    if(arr[i]>=arr[i-1])
    {
        inc[i]=(inc[i-1]+1);
    }
    else if(arr[i]<arr[i-1])
    {
        inc[i]=1;
    }
}
for(int i=n-2;i>=0;i--)
{
if(arr[i]>=arr[i+1])
    {
        dec[i]=(dec[i+1]+1);
    }
    else if(arr[i]<arr[i+1])
    {
        dec[i]=1;
    }
}
mmax=(inc[0]+dec[0]-1);
for(int i=1;i<n;i++)
{
  if((inc[i]+dec[i]-1)>mmax)
  {
      mmax=(inc[i]+dec[i]-1);
  }

}



cout<<mmax<<endl;
}



return 0;
}
