#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
void clearbit(int &n, int pos)
{
	int mask = ~(1 << pos);
	n = n & mask;
}
void updatebit(int &n, int pos, int bit)
{
	clearbit(n, pos);
	int mask = bit << pos;
	n = n | mask;
}
int getbit(int n, int i)
{
	int mask = (1 << i);
	int bit =  ((n & mask) > 0) ? 1 : 0;
	return bit;
}
void display_adeq_ans(int w, int s, int e)
{

	int ans = 0;
	int p = 1;
	for (int i = s; i <= e; i++)
	{

		int bit = getbit(w, i);

		bit = (bit * p) % mod;
		ans += bit % mod;
		p = (p * 2) % mod;

	}
	cout << ans % mod;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int w = 0;
	int q;
	cin >> q;
	while (q--)
	{
		int type;
		cin >> type;

		int s, e;
		cin >> s >> e;
		int act_start_point = n - e - 1;
		int act_end_point = n - s - 1;
		if (type == 0)
		{
			for (int i = act_start_point; i <= act_end_point; i++)
			{
				updatebit(w, i, 0);
			}
		}
		else if (type == 1)
		{
			for (int i = act_start_point; i <= act_end_point; i++)
			{
				updatebit(w, i, 1);
			}

		}


		else if (type == 2)
		{
			display_adeq_ans(w, act_start_point, act_end_point) ; cout << endl;
		}
	}

	return 0;
}
