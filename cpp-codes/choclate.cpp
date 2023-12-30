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
	//cin>>t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;

		m--;
		n--;

		int x_array[m];
		int y_array[n];

		for (int i = 0; i < m; i++)
		{
			cin >> x_array[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> y_array[i];
		}

		sort(x_array, x_array + m);
		sort(y_array, y_array + n);

		int vert_pieces = 1;
		int hori_pieces = 1;

		int total_cost = 0;


		int i = m - 1;
		int j = n - 1;

		while (i >= 0 && j >= 0)
		{
			if (x_array[i] >= y_array[j])
			{
				total_cost += x_array[i] * vert_pieces;
				hori_pieces++;
				i--;
			}
			else
			{
				total_cost += y_array[j] * hori_pieces;
				vert_pieces++;
				j--;
			}

			//wer(total_cost);
		}


		while (i >= 0)
		{
			total_cost += x_array[i] * vert_pieces;
			hori_pieces++;
			i--;
		}

		while (j >= 0)
		{
			total_cost += y_array[j] * hori_pieces;
			vert_pieces++;
			j--;
		}


		cout << total_cost << endl;

	}
	return 0;
}
