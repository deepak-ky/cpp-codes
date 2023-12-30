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

unordered_map<int, int> cost_from_here;
unordered_map<int, int> next_jump;

int solve(int *a, int idx, int l, int n)
{
	//If I have been previously at this index before
	if (cost_from_here.find(idx) != cost_from_here.end())
	{
		return cost_from_here[idx];
	}
	if (idx == (n - 1))
	{
		next_jump[n - 1] = n - 1;
		return 0;
	}
	if (idx == n)
	{
		return 0;
	}


	int min_cost = INT_MAX;
	int total_curr_length = 0;
	for (int i = idx; i < n; i++)
	{
		total_curr_length += a[i];
		if (l - total_curr_length >= 0 )
		{
			if (i == n - 1)
			{
				min_cost = 0;
				next_jump[idx] = n - 1;
			}
			else
			{
				int spaces_left = l - total_curr_length;
				int f1 = pow(spaces_left, 2) + solve(a, idx + 1, l, n);
				if (f1 < min_cost)
				{
					min_cost = f1;
					next_jump[idx] = i;
				}

			}
		}
		else
		{
			break;
		}
		total_curr_length++;
	}


	return cost_from_here[idx] = min_cost;
}



int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{


		next_jump.clear();
		cost_from_here.clear();


		vector<string> v = {"This", "is", "an", "example", "of", "text", "justification."};
		int n = v.size();
		int l = 16;


		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			a[i] = v[i].length();
		}
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}

		solve(a, 0, l, n);

		vector<int> pattern;

		int start = 0;
		while (start != n)
		{
			pattern.pb(start);
			pattern.pb(next_jump[start]);
			start = next_jump[start] + 1;
		}

		vector<string> ans;


		int i = 0;
		while (i < (pattern.size() - 2))
		{
			int a1 = pattern[i];
			int a2 = pattern[i + 1];


			string w = "";

			int number_of_words = a2 - a1 + 1;


			if (number_of_words == 1)
			{
				w += v[a1];
				int rem_length = l - v[a1].length();
				string spaces = "";
				for (int j = 0; j < rem_length; j++) spaces += " ";
				w += spaces;

				ans.pb(w);
			}
			else
			{
				int rem_length = l;
				for (int j = a1; j <= a2; j++)
				{
					rem_length -= v[a1] - length();
				}

				string w = "";

				if (rem_length % (number_of_words - 1) == 0)
				{
					string spaces = "";
					for (int j = 0; j < (rem_length / (number_of_words - 1)); j++) spaces += " ";
					int k = a1;
					while (1)
					{
						w += v[k];
						k++;
						if (k == a2)
						{
							break;
						}
						w += spaces;
					}


					ans.pb(w);


				}
				else
				{
					int p = (rem_length / (number_of_words - 1));
					int r = (rem_length % (number_of_words - 1));
					string spaces = "";
					for (int j = 0; j < (rem_length / (number_of_words - 1)); j++) spaces += " ";
					string special_space = "";
					for (int j = 0; j < (r); j++) special_space += " ";




				}
			}


		}



	}
	return 0;
}
