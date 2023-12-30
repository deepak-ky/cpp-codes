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
		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			mp[a[i]] = i + 1;
		}
		int wrong_indices = 0;
		vector<int> wrong_index;
		for (auto x : mp)
		{
			if (x.first != x.second)
			{
				wrong_indices++;
				wrong_index.push_back(x.second);
			}
		}
		//wer(wrong_indices);
		if (wrong_indices == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			bool flag = true;
			//need to check if all the indexes in the wrong index array are consecutive
			//if they are then it will only take 1 special exchange to sort the array
			sort(wrong_index.begin(), wrong_index.end());
			/*	for (auto x : wrong_index)
				{
					cout << x << " ";
				}*/
			for (int i = 1; i < wrong_index.size(); i++)
			{
				if (wrong_index[i] != wrong_index[i - 1] + 1)
				{
					cout << "here";
					flag = false;
					break;
				}
			}
			if (flag)
			{
				cout << 1 << endl;
			}
			else cout << 2 << endl;
		}
	}
	return 0;
}
