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
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bool flag = true;
	if (n == 1 || n == 2)
	{
		cout << "no";
	}
	else
	{
		int lb = min(a[0], a[1]);
		int ub = max(a[0], a[1]);
		for (int i = 2; i < (n - 1); i++)
		{
			if (a[i] > ub)
			{
				if (a[i + 1] > a[i])
				{
					ub = a[i];
				}
				else if (a[i + 1] < lb)
				{
					ub = a[i];
				}
				else if (a[i + 1] > ub && a[i + 1] < a[i])
				{
					lb = ub;
					ub = a[i];
				}
				else
				{
					flag = false;
					cout << "yes";
					break;
				}
			}
			else if (a[i] < lb)
			{
				if (a[i + 1] < a[i])
				{
					lb = a[i];
				}
				else if (a[i + 1] > ub)
				{
					lb = a[i];
				}
				else if (a[i + 1] > a[i] && a[i + 1] < lb)
				{
					lb = a[i];
					ub = lb;
				}
				else
				{
					flag = false;
					cout << "yes";
					break;
				}

			}
			else
			{
				if (a[i + 1] > ub || a[i + 1] < lb)
				{
					flag = false;
					cout << "yes";
					break;
				}
				else if (a[i + 1] > lb && a[i + 1] < a[i])
				{
					ub = a[i];
				}
				else if (a[i + 1] > a[i] && a[i + 1] < ub)
				{
					lb = a[i];
				}
			}
		}
		if (flag) cout << "no";
	}



	return 0;
}
