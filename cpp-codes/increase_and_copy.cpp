#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back

int best_moves;

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
		int num = 1;
		int best_moves = INT_MAX;
		while (true)
		{
			int w = n - num;
			int k = w / num;
			int total_moves_here = num - 1;
			if (w % num == 0)
			{
				total_moves_here += k;
			}
			else
			{
				total_moves_here += k + 1;
			}
			if (total_moves_here > best_moves)
				break;
			best_moves = min(best_moves, total_moves_here);
			num++;
		}
		cout << best_moves << endl;
	}
	return 0;
}
