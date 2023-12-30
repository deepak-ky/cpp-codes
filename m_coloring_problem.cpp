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


bool is_safe_to_color(int node , unordered_map<int, list<int>> mp, int *color, int curr_color)
{
	for (auto nbr : mp[node])
	{
		if (color[nbr] == curr_color)
		{
			return false;
		}
	}
	return true;
}

//I am going simple indexing with this

bool can_fill(int node ,  unordered_map<int, list<int>> mp , int *color , int n , int m)
{
	if (node == n + 1)
	{
		return true;
	}

	for (int c = 1; c <= m; c++)
	{
		if (is_safe_to_color(node, mp, color, c))
		{
			color[node] = c;
			bool can_I_color_the_rest_successfully = can_fill(node + 1, mp, color, n, m);
			if (can_I_color_the_rest_successfully == true)
			{
				return true;
			}
			else
			{
				color[node] = -1;
			}



		}
	}

	return false;

}




int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n = 4;
		unordered_map<int, list<int>> mp;
		mp[1].pb(2);
		mp[1].pb(3);
		mp[1].pb(4);

		mp[2].pb(1);
		mp[2].pb(3);

		mp[3].pb(1);
		mp[3].pb(2);
		mp[3].pb(4);

		mp[4].pb(1);
		mp[4].pb(3);


		int *color = new int[n + 1];
		for (int i = 0; i < n + 1; i++)
		{
			color[i] = -1;
		}

		int m = 3;


		bool flag = can_fill(1, mp, color, n, m);

		if (flag)
		{
			cout << "Color can be done\n";
			for (int i = 1; i < n + 1; i++)
			{
				cout << i << " : " << color[i] << endl;
			}
		}
		else cout << "No";


	}
	return 0;
}
