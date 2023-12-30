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

class circle
{
public:
	int circle_start;
	int circle_end;

};

bool compare(circle c1, circle c2)
{
	if (c1.circle_end <= c2.circle_end)
	{
		return true;
	}
	else return false;
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
		if (n <= 100000) {
			circle*  c = new circle[n];
			for (int i = 0; i < n; i++)
			{
				int x, y;
				cin >> x >> y;
				c[i].circle_start = x - y;
				c[i].circle_end = x + y;
			}
			sort(c, c + n, compare);
			int cnt = 1;
			int curr_end = c[0].circle_end;
			int i = 1;
			while (i < n)
			{
				if (c[i].circle_start >= curr_end)
				{
					cnt++;
					curr_end = c[i].circle_end;
				}
				i++;
			}
			cout << n -  cnt << endl;
		}
		else cout << "99999";

	}
	return 0;
}
