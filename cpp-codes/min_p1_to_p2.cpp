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
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{

cin>>a[i];

}
int r=minimum(a,2,5);
cout<<r;
cout<<"\nWithout Updating : ";
for(int i=0;i<n;i++)
{

cout<<a[i];

}
update(a,3,9);
cout<<"\nAfter Updating : ";
for(int i=0;i<n;i++)
{

cout<<a[i];

}




return 0;
}
