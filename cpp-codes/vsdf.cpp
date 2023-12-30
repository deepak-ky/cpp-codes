#include<iostream>
using namespace std;
int linearsrch(int *a,int n,int key)
{
 if(n==0)
 {
 return -1;
 }
 if(a[0]==key)
 {
 return a+1;
 }
 return linearsrch(a+1,n-1,key);
}
int main()
{
 int a[]={1,2,3,6,3,7};
 int n=sizeof(a)/sizeof(int);
 int key=3;
 cout<<linearsrch(a,n,key);
 return 0;
}













