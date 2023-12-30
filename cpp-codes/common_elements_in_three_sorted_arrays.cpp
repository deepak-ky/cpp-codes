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

		int n1;
		cin >> n1;
		int *a = new int[n1];
		for (int i = 0; i < n1; i++)
		{
			cin >> a[i];
		}
		int n2;
		cin >> n2;
		int *b = new int[n2];
		for (int i = 0; i < n2; i++)
		{
			cin >> b[i];
		}
		int n3;
		cin >> n3;
		int *c = new int[n3];
		for (int i = 0; i < n3; i++)
		{
			cin >> c[i];
		}

		//METHOD - 1
		int i = 0;
		int j = 0;
		int k = 0;
		vector<int> final_ans;
		while (i < n1 && j < n2 && k < n3)
		{
			if (a[i] == b[j] && b[j] == c[k])
			{
				final_ans.push_back(a[i]);
				i++;
				j++;
				k++;
			}
			else if (a[i] < b[j])
			{
				i++;
			}
			else if (b[j] < c[k])
			{
				j++;
			}
			else k++;
		}




		//METHOD - 2


		/*vector<int> ans;
		int i = 0;
		int j = 0;
		while (i < n1 && j < n2)
		{

			if (a[i] == b[j])
			{
				ans.push_back(b[j]);
				i++;
				j++;
			}
			else if (a[i] < b[j])
			{
				i++;
			}
			else j++;
		}


		int n = ans.size();
		vector<int> final_ans;
		i = 0;
		j = 0;
		while (i < n && j < n3)
		{
			if (ans[i] == c[j])
			{
				final_ans.push_back(ans[i]);
				i++;
				j++;
			}
			else if (ans[i] < c[j])
			{
				i++;
			}
			else j++;
		}*/

		vector<int> after_removing_duplicates;
		if (final_ans.empty())
		{
			after_removing_duplicates.push_back(-1);
		}
		else
		{
			int size = final_ans.size();
			after_removing_duplicates.push_back(final_ans[0]);
			int prev = final_ans[0];
			int p = 1;
			while (p < size)
			{

				if (final_ans[p] == prev)
				{

					p++;
				}
				else
				{

					prev = final_ans[p];
					after_removing_duplicates.push_back(prev);
					p++;
				}
			}

			for (auto x : after_removing_duplicates)
			{
				cout << x << " ";
			}

		}

	}
	return 0;
}
