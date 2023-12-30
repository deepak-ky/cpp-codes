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
bool triplet_exists(int *a, int s, int e, int m)
{
	while (s < e)
	{
		int w = (a[s] * a[s]) + (a[e] * a[e]);
		if (w == m) return true;
		else if (w < m)
		{
			s++;
		}
		else
		{
			e--;
		}
	}
	return false;
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
		asdf(a, n);
		//sort(a, a + n);

		//O(N^2) Approach


		// bool flag = false;
		// for (int i = 2; i < n; i++)
		// {
		// 	if (triplet_exists(a, 0, i - 1, a[i] * a[i]))
		// 	{
		// 		flag = true;
		// 		break;
		// 	}
		// }
		// if (flag)
		// {
		// 	cout << "Yes";
		// }
		// else cout << "No";

		//O(max_ele * max_ele) approach
		int max_ele = *max_element(a, a + n);
		map<int, bool> mp;
		for (int i = 1; i <= (max_ele); i++)
		{
			mp[i] = false;
		}
		for (int i = 0; i < n; i++)
		{
			mp[a[i]] = true;
		}
		bool flag = false;
		for (int i = 1; i <= max_ele; i++)
		{
			for (int j = i + 1; j <= max_ele; j++)
			{
				int val = sqrt(i * i + j * j);
				if ((val * val) != (i * i + j * j))
				{
					continue;
				}
				if (val > max_ele)
				{
					continue;
				}
				if (mp[val] && mp[i] && mp[j])
				{
					flag = true;
					break;
				}

			}
		}
		if (flag)
		{
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}


	return 0;
}
