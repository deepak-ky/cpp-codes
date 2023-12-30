#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
int* merge(int a[], int b[], int len1, int len2)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int c[len1 + len2];
	while (i < len1 && j < len2)
	{
		if (a[i] <= b[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else if (a[i] > b[j])
		{
			c[k] = b[j];
			j++;
			k++;
		}
	}
	while (i < len1)
	{
		c[k] = a[i];
		k++;
		i++;
	}
	while (j < len2)
	{
		c[k] = b[j];
		k++;
		j++;
	}
	return c;

}

int* merge_sort(int a[], int i, int j)
{
	// if(i == j)
	// {
//        return;
	// }
	if (i < j)
	{
		int mid = (i + j ) / 2;
		merge_sort(a, i, mid);
		merge_sort(a, mid + 1, j);
		merge()
	}

}
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {5, 2, 8, 1, 4};
	int b[] = {5, 6};
	int *
	return 0;
}
