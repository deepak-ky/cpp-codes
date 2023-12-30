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
bool is_good_array(int a, int n)
{
	int b[n - 1];
	int c[n - 1];

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
	test
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		//int min_element = *min_element(a, a + n);
		int left_highest[n];
		int right_highest[n];
		left_highest[0] = a[0];
		int max_left = a[0];
		for (int i = 1; i < n; i++)
		{
			if (a[i] > max_left)
			{
				left_highest[i] = a[i];
				max_left = a[i];
			}
			else left_highest[i] = max_left;
		}
		right_highest[n - 1] = a[n - 1];
		int max_right = a[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			if (a[i] > max_right)
			{
				right_highest[i] = a[i];
				max_right = a[i];
			}
			else right_highest[i] = max_right;
		}
		//out(left_highest, n);
		//out(right_highest, n);
		int flag = true;
		int ans_index = -1;
		for (int i = (n - 1); i >= 0; i--)
		{

			if ((a[i] < left_highest[i]) && (a[i] < right_highest[i]))
			{
				//cout << "hrere";
				//wer(a[i]); wer(left_highest[i]); wer(right_highest[i]);
				flag = false;
				ans_index = i;
				break;

			}
		}

		if (flag)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << ans_index << endl;

		}
	}

	return 0;
}
