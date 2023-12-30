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
#define s                            second

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

int gcd;
int x;
int y;

void solve(int a, int b)
{
	if (b == 0)
	{
		gcd = a;
		x = 1;
		y = 0;
		return;
	}

	solve(b , a % b);
	int c_x = y;
	int c_y = x - (a / b) * y;

	x = c_x;
	y = c_y;

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
		int prod = 1;
		int num[n];
		int rem[n];
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
			prod *= num[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> rem[i];
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int pp = prod / num[i];
			//wer(pp);
			//wer(num[i]);
			x = 0;
			y = 0;
			gcd = 0;
			solve(pp, num[i]);
			int inv = (x + num[i]) % num[i];
			//cout << inv << endl;

			ans += rem[i] * pp * inv;

		}
		cout << ans % prod << endl;
	}
	return 0;
}
