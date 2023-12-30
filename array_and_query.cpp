#include<iostream>
using namespace std;
int minimum(int a[],int p1,int p2)
{
  int min=a[p1-1];
  for(int i=p1;i<p2;i++)
    {
      if(a[i]<min)
      {min=a[i];}

    }
return min;
}
void update(int a[],int p,int data)
{
    a[p-1]=data;
}
int main()
{
int n,q;
cin>>n>>q;
int a[n];
int b[q];
for(int i=0;i<n;i++)
{
cin>>a[i];
}
int j=0;
for(int i=0;i<q;i++)
{
   int choice;
   cin>>choice;
   if(choice==1)
   {
       int l,r;
       cin>>l>>r;
       int w=minimum(a,l,r);
       b[j]=w;
       j++;
   }
   else if(choice==2)
   {
       int x,y;
       cin>>x>>y;
       update(a,x,y);
   }
}
cout<<"\nAnswers : ";
for(int i=0;i<j;i++)
{
cout<<b[i];
cout<<endl;
}
return 0;
}
