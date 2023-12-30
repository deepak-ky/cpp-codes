#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long int smallelement(long long int arr[],long long int a)
{
    long long int temp=arr[0];
    for(long long int g=0;g<a;g++)
    {
        if(arr[g]<temp)
        {
            temp=arr[g];
        }
    }
 return temp;
}
long long int fllag = 0;
long long int mincount[100];
long long int j=0;
void isSubsetSum(long long int arr[], long long int subset[], long long int N, long long int subsetSize,
                             long long int subsetSum, long long int index ,long long int sum)
{
    if (subsetSum == sum)
    {
       fllag = 1;
        long long int count=0;

        for (long long int i = 0; i < subsetSize; i++)
        {
            count++;

        }
            mincount[j++]=count;

    }
    else
    {
        for (long long int i = index; i < N; i++)
        {
            subset[subsetSize] = arr[i];
            isSubsetSum(arr, subset, N, subsetSize + 1,
                        subsetSum + arr[i], i + 1, sum);
        }
    }
}
long long int checkprime(long long int a)
{
 for(long long int i=2;i<=a/2;i++)
 {
 if(a%i==0)
 {
  return 1;
  break;
 }
}
return 2;
}
int main()
{
long long int n,flag;

cin>>n;
long long int a[n];
long long int b[100];
long long int b1=0;
long long int k=0;
for(long long int i=2;i<=n;i++)
{
    flag=checkprime(i);
    if (flag==1)
    {
        b[b1++]=i;
    }
    else if(flag==2)
    {
        a[k++]=i;

    }
}
long long int *subset = new long long int[k];
isSubsetSum(a, subset, k, 0, 0, 0, n);
    if (fllag == 0) {
        cout << "No such subset present" << endl;
    }
long long int h=smallelement(mincount,j);
 cout<<h;
return 0;
}
