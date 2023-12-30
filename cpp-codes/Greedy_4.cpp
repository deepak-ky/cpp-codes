#include<iostream>
using namespace std;
int sum(int a[],int i,int j)
{
      int ld=0;
    for(int k=i;k<=j;k++)
    {
        ld=ld+a[k];
    }
    return ld;
}
int abs(int a,int b)
{
    if(a>b)
    {
        return a-b;
    }
    else return b-a;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int load=0;
    int maxload=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        load+=a[i];
    }
    if(load%n!=0)
    {
        cout<<-1<<endl;
    }
    else load=load/n;
    int diff1=0;
     for(int i=0;i<n;i++)
     {
         int w=sum(a,0,i);
         cout<<"\nSum till now : "<<w<<endl;
         int z=load*(i+1);
         cout<<"\nshould be Sum till now : "<<z<<endl;
         diff1=abs(w,z);
         cout<<"\ndiff now : "<<diff1<<endl;
         maxload=max(diff1,maxload);
     }
     cout<<endl<<maxload;
    return 0;
}
