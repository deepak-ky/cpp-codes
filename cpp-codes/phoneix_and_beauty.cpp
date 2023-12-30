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
int get_sum_of_subarray(vector<int> v, int i, int k)
{
	int sum = 0;
	for (int j = i; j < (i + k); j++)
	{
		sum = sum + v[j];
	}
	return sum;
}
int check_if_all_equal(vector<int> v, int k, int n)
{
	int couldbesum = get_sum_of_subarray(v, 0, k);
	for (int i = 1; i <= (n - k); i++)
	{
		int w = get_sum_of_subarray(v, i, k);
		if (w != couldbesum)
		{
			return i;
		}
	}
	return -5;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n;
		int k;
		cin >> n >> k;
		vector<int> v;
		int nos = (n - k) + 1;

		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			v.push_back(w);
		}
		if (k == 1)
		{
			int flag = 0;
			for (int i = 0; i < (n - 1); i++)
			{
				if (v[i] != v[i + 1])
				{

					cout << -1 << endl;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cout << n << endl;
				for (auto x : v)
				{
					cout << x << " ";
				}
				cout << endl;
			}
		}
		else if (k == n)
		{
			cout << n << endl;
			for (auto x : v)
			{
				cout << x << " ";
			}
			cout << endl;
		}
		else
		{

			//cout << endl << couldbesum;
			int size = n;
			//we will try to make the sum of every subarray equal to the sum of first subarray
			//inserting elements from the back of the subarray
			int d = check_if_all_equal(v, k, n);
			if (d == -5)
			{
				cout << n << endl;
				for (auto x : v)
				{
					cout << x << " ";
				}
				cout << endl;
			}
			cout << "\nWe have reached here an " ;
			v.insert(v.begin() + d, 500);
			cout << "\nThe arrary now : ";
			for (auto x : v)
			{
				cout << x << " ";
			}
			cout << endl;

		}



	}
	return 0;
}
