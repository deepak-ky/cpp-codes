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

		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int left_product[n];
		int right_product[n];

		left_product[0] = a[0];
		for (int i = 1; i < n; i++)
		{
			left_product[i] = left_product[i - 1] * a[i];
		}

		right_product[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			right_product[i] = right_product[i + 1] * a[i];
		}


		int ans[n];
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				ans[i] = right_product[1];
			}
			else if (i == n - 1)
			{
				ans[i] = left_product[i - 1];
			}
			else
			{
				ans[i] = right_product[i + 1] * left_product[i - 1];
			}
		}


		for (auto x : ans)
		{
			cout << x << " ";
		}

	}
	return 0;
}
