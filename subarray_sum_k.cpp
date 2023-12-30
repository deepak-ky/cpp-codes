#include<iostream>
using namespace std;
bool check_for_subarray(int a[],int n,int sum)
{
int currsum=a[0];
int start=0;
for(int i=1;i<=n;i++)
{
 while(currsum>sum && start<i-1)
 {currsum=currsum-a[start];
 start++;}
if(currsum==sum)
{return true;}
if(i<n)
{currsum=currsum+a[i];}

}

return false;


}
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{cin>>a[i];}
int sum;
cin>>sum;
if(check_for_subarray(a,n,sum))
{cout<<"YES";}
else cout<<"NO";
return 0;
}
