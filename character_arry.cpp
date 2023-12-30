#include<iostream>
using namespace std;
int main()
{
  int a[]={1,2,3,4,5,6};
  cout<<a[1]<<endl;
  char b[]={'a','b','c','\0'};
  cout<<b<<endl;
  char d1[]={'d','e','e','w','\0','a','h','\0'};
  char d2[]="deepak";
  cout<<d1<<endl<<d2<<endl;
  char e[100];
  cin.getline(e,100);
  cout<<endl<<e;
}
