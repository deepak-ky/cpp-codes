#include<iostream>
using namespace std;
fact(int a)
{
    if(a==1)
        return 1;
    else return a*fact(a-1);
}
int main()
{
    int n,r;
 cout<<"enter n";
 cin>>n;
 r=fact(n);
 cout<<endl;
 cout<<r;
  return 0;




}
