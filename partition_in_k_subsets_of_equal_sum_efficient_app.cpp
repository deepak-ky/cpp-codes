#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define se                            second

void init()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

bool is_visited[18];

bool can_be_partitoned(int idx, int *a, int n, int k, int curr_sum, int req_sum)
{
	if (k == 1)
	{
		return true;
	}

	if (curr_sum > req_sum)
	{
		return false;
	}

	if (curr_sum == req_sum)
	{
		return can_be_partitoned(0, a, n, k - 1, 0, req_sum);
	}

	for (int i = idx; i < n; i++)
	{
		if (is_visited[i] == false)
		{
			is_visited[i] = true;
			bool aage_sahin_hain = can_be_partitoned(idx + 1, a, n, k, curr_sum + a[i], req_sum);
			if (aage_sahin_hain)
			{
				return true;
			}
			is_visited[i] = false;
		}
	}

	return false;

}



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		for (int i = 0; i < 18; i++)
		{
			is_visited[i] = false;
		}

		int n;
		cin >> n;
		int *a = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}

		int k;
		cin >> k;
		if ((sum % k != 0) || k > n)
		{

			no;
		}
		else
		{
			if (can_be_partitoned(0, a, n, k, 0, sum / k))
			{
				yes;
			}
			else no;
		}
	}
	return 0;
}
