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

double solve(double a, double b)
{
	double a2 = a * a;
	double b2 = b * b;
	double ret = sqrt(a2 + b2);
	//wer(ret);
	return ret;
}

int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> x_coord;
		vector<int> y_coord;
		for (int i = 0; i < (2 * n); i++)
		{
			int x, y;
			cin >> x >> y;
			if (x == 0)
			{
				y = abs(y);

				y_coord.pb(y);
			}
			else
			{
				x = abs(x);
				x_coord.pb(x);
			}
		}
		sort(x_coord.begin(), x_coord.end());
		sort(y_coord.begin(), y_coord.end());
		double ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += sqrt((1.0 * x_coord[i] * x_coord[i]) + (1.0 * y_coord[i] * y_coord[i]));
		}

		cout << fixed << setprecision(15) << ans << endl;

	}
	return 0;
}
