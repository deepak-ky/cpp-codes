#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
int subsequence_sum(int a, int arr[], int n)
{
	int j = 0;
	int sum = 0;

	while (a > 0)
	{
		int lastbit = (a & 1);
		if (lastbit)
		{

			sum = sum + arr[j];
		}
		j++;
		a = a >> 1;
	}
	return sum;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int getsum;
	cin >> getsum;
	int a[n];
	asdf(a, n);

	int flag = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		if (subsequence_sum(i, a, n) == getsum)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
