#include<iostream>
using namespace std;
int getbit(int n,int i)
{
    int mask=(1<<i);
    int bit=(mask&n)>0?1:0;
    return bit;
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
int count=0;
for(int i=0;i<n;i++)
{
if(a[i]&1)
{
count++;
}
}
for(int i=0;i<(n-count);i++)
{
    cout<<"0"<<" ";
}
for(int i=0;i<count;i++)
{
    cout<<"1"<<" ";
}
return 0;

}
