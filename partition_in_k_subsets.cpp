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

void  partition_in_k_subsets(int idx, int *a, int n, int k, unordered_map<int, vector<int>> mp)
{
	if (idx == n)
	{
		bool is_any_set_empty = false;
		for (int i = 0; i < k; i++)
		{
			if (mp[i].size() == 0)
			{
				is_any_set_empty = true;
				break;
			}
		}

		if (!is_any_set_empty)
		{
			for (int i = 0; i < k; i++)
			{
				for (auto x : mp[i])
				{
					cout << x << " ";
				}
				cout << " | ";
			}

			cout << endl;
		}

		return;

	}


	//For every element I have predominantly two choices - > whether I put it in a vector which already has
	//some elements or create a new one

	bool assigned_to_a_empty_set = false;

	for (int i = 0; i < k; i++)
	{
		if (mp[i].size() > 0)
		{
			//the vector is not empty
			mp[i].push_back(a[idx]);
			partition_in_k_subsets(idx + 1, a, n, k, mp);
			mp[i].pop_back();

		}
		else
		{
			if (assigned_to_a_empty_set == false)
			{
				mp[i].push_back(a[idx]);
				partition_in_k_subsets(idx + 1, a, n, k, mp);
				mp[i].pop_back();
				assigned_to_a_empty_set = true;
			}
			else continue;
		}
	}


	return;
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

		int k;
		cin >> k;


		//I have to divide the array into k - non - empty subsets

		if (k > n)
		{
			cout << "-1" << endl;
		}
		else
		{
			unordered_map<int, vector<int>> mp;
			partition_in_k_subsets(0, a, n, k, mp);
		}

	}
	return 0;
}
