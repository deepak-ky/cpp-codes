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
	int c = 1;
	while (t--)
	{
		int n, k, b, time;

		cin >> n >> k >> b >> time;

		int min_swaps_req = 0;   // Chicks that cannot reach have to be swapped
		int chicks_that_cannot_reach = 0;
		int chicks_that_can_reach = 0;


		int x_array[n];
		for (int i = 0; i < n; i++)
		{
			cin >> x_array[i];
		}

		int v_array[n];
		for (int i = 0; i < n; i++)
		{
			cin >> v_array[i];
		}


		for (int i = n - 1; i >= 0; i--)
		{
			//wer(x_array[i]);
			int dist_needed_to_cover = b - x_array[i];
			//wer(dist_needed_to_cover);

			int can_cover_dist = v_array[i] * time;   // Distance = speed * time
			//wer(can_cover_dist);

			if (can_cover_dist >= dist_needed_to_cover)
			{
				min_swaps_req += chicks_that_cannot_reach;
				chicks_that_can_reach++;
			}
			else
			{
				chicks_that_cannot_reach++;
			}

			//wer(chicks_that_can_reach);



			if (chicks_that_can_reach == k)
			{
				break;
			}
		}


		if (chicks_that_can_reach == k)
		{
			cout << "Case #" << c << ": " << min_swaps_req << endl;
		}
		else
		{
			cout << "Case #" << c << ": " << "IMPOSSIBLE" << endl;

		}
		c++;





	}
	return 0;
}
