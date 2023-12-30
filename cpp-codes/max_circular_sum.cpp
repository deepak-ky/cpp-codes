#include<iostream>
#include<climits>
using namespace std;
int kadanesum(int a[],int n)
{
    int sum=0;
	int maxsum=INT_MIN;
	for(int i=0;i<n;i++)
	{
      sum=sum+a[i];
	  maxsum=max(sum,maxsum);
	  if(sum<0)
	    {
			sum=0;
		}
    }
return maxsum;




}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int max_of_full_array=kadanesum(a,n);
	int sum_of_full_array=0;
	for(int i=0;i<n;i++)
    {
        sum_of_full_array+=a[i];
    }
    //Inverting the sum
    for(int i=0;i<n;i++)
    {
        a[i]=-a[i];
    }
    int negsum_of_full_array=kadanesum(a,n);
    cout<<max((max_of_full_array),(sum_of_full_array+negsum_of_full_array))<<endl;
	}
	return 0;
}
