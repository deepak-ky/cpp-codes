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
	cin >> t;
	while (t--)
	{
		int w, h, n;
		cin >> w >> h >> n;
		int x_array[n] , y_array[n];

		if (n == 0)
		{
			cout << w*h << endl;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				cin >> x_array[i] >> y_array[i];
			}

			sort(x_array, x_array + n);
			sort(y_array, y_array + n);

			int max_x = x_array[0] - 1;
			int max_y = y_array[0] - 1;
			for (int i = 1; i < n; i++)
			{
				int u = x_array[i] - x_array[i - 1] - 1;
				int q = y_array[i] - y_array[i - 1] - 1;
				max_x = max(max_x, u);
				max_y = max(max_y, q);

			}
			max_x = max(max_x , w - x_array[n - 1]);
			max_y = max(max_y , h - y_array[n - 1]);

			cout << max_x * max_y << endl;
		}

	}
	return 0;
}
