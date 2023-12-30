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



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int n = 5;
		int a[n] = {1, 4, 6, 8, 10};

		int prefix_sum[n];
		prefix_sum[0] = a[0];

		for (int i = 1; i < n; i++)
		{
			prefix_sum[i] = a[i] + prefix_sum[i - 1];
		}


		//For every element the ans is the sum of two values , which
		// how much extra on the right
		// how much less on the left

		int ans[n];

		for (int i = 0; i < n; i++)
		{
			int right_ans = 0;
			int left_ans = 0;

			int no_of_element_on_Right = n - i - 1;
			int sum_of_right =  prefix_sum[n - 1] - prefix_sum[i];
			right_ans = sum_of_right - (no_of_element_on_Right * a[i]);

			if (i != 0)
			{

				int no_of_element_on_left = i;
				int sum_of_left =  prefix_sum[i - 1];
				left_ans = (no_of_element_on_left * a[i]) - sum_of_left;
			}
			ans[i] = left_ans + right_ans;

		}


		for (auto x : ans) cout << x << " ";

	}
	return 0;
}
