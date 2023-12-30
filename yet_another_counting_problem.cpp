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

const int N = 4000000;
int v[N];

int x_in_ab;

void build_array(int a, int b)
{
	for (int i = 0; i < a * b; i++)
	{
		if ( ((i % a) % b) != ((i % b) % a))
		{
			v[i] = 1;
		}
	}
}
int cnt_x(int y, int a, int b)
{
	int a1 = y / (a * b);
	a1 *= x_in_ab;
	int a2 = 0;
	for (int i = 0; i <= ( y % (a * b)); i++)
	{
		if (v[i] == 1)
		{
			a2++;
		}
	}
	return a1 + a2;
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
		int a, b, q;
		cin >> a >> b >> q;
		memset(v, 0, sizeof(v));
		x_in_ab = 0;
		build_array(a, b);
		for (int i = 0; i < a * b; i++)
		{
			if (v[i] == 1)
			{
				x_in_ab++;
			}
		}
		//out(v, a * b);
		//cout << x_in_ab << endl;
		while (q--)
		{
			int r, l;
			cin >> r >> l;
			cout << cnt_x(l, a, b) - cnt_x(r - 1, a, b) << " ";

		}
		cout << endl;
	}
	return 0;
}
