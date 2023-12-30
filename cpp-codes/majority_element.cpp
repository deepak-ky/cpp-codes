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
int find_candidate(int *a, int n)
{
	int cand = a[0];
	int cand_index = 0;
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == cand)
		{
			cnt++;
		}
		else if (a[i] != cand)
		{
			cnt--;
		}
		if (cnt == 0)
		{
			//equal number of dis similiar characters are present
			cand = a[i];
			cnt = 1;
		}
	}
	return cand;
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
	//Sorting Approach
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	// sort(a, a + n);
	// int temp = a[0];
	// int ans = a[0];
	// int cnt = 1;
	// int max_cnt = 1;
	// for (int i = 1; i < n; i++)
	// {
	// 	if (a[i] == a[i - 1])
	// 	{
	// 		cnt++;
	// 	}
	// 	else
	// 	{
	// 		temp = a[i];
	// 		cnt = 1;
	// 	}
	// 	if (cnt > max_cnt)
	// 	{
	// 		max_cnt = cnt;
	// 		ans = a[i];
	// 	}
	// }
	// if (max_cnt > n / 2)
	// {
	// 	cout << ans << endl;
	// }
	// else cout << -1;

	//Moores Voting Algorithm
	int candidate = find_candidate(a, n);
	//wer(candidate);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == candidate) cnt++;
	}
	if (cnt > n / 2)
	{
		cout << candidate;
	}
	else cout << -1;

	return 0;
}
