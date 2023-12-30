#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a,int b)
{
    return a<=b;
}
int main()
{
    int a[]={1,2,5,10,20,50,100,200,500,1000};
    int n=sizeof(a)/sizeof(int);
    int money;
    cin>>money;
    while(money>0)
    {
     int* lb=upper_bound(a,a+n,money)-1;
    cout<<a[lb-a]<<",";
    money=money-a[lb-a];
    }





}
