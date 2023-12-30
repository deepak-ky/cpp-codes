#include <iostream>
#include<stdlib.h>
using namespace std;
int main()
{
int i,j,k,l;
j=0;
int n = 1000;
int a[n];
for(i=0;i<1000;i++)
{
	cin>>a[i];
    if(a[i]==42)
     {
         break;
     }
	j++;
}
for(i=0;i<j;i++)
{
	cout<<"\n"<<a[i];
}
	return 0;
}







