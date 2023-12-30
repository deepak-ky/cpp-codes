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

int check_validity(int n, int x, int y, int d, int i)
{
	bool check_x = false;
	bool check_y = false;
	int s = i;
	for (int j = 0; j < n; j++)
	{
		if (s == x) check_x = true;
		if (s == y) check_y = true;
		s = s + d;
	}
	if (check_x &&  check_y)
	{
		return 1;
	}
	else return -1;
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
		int n , x , y;
		cin >> n >> x >> y;
		if ( n == 2)
		{
			cout << x << " " << y << endl;
		}
		else
		{
			bool check = false;
			for (int d = 1; d <= (y - x); d++)
			{
				for (int i = 1; i <= x; i++)
				{
					if (check_validity(n, x, y, d, i) != -1)
					{
						for (int j = 0; j < n; j++)
						{
							cout << i << " ";
							i = i + d;
						}
						cout << endl;
						check = true;
						break;

					}
				}
				if (check) break;
			}
		}
	}
	return 0;
}
