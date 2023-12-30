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

bool is_suitable_index(int *a, int n, int idx)
{
	int i = idx;

	int cal = a[idx];

	i = (i + 1) % n;

	while (i != idx)
	{


		cal = cal + a[i];

		if (cal < 0)
		{
			return false;
		}


		i = (i + 1) % n;
	}


	return true;


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

		int *petrol   = new int[n];
		int *distance = new int[n];

		for (int i = 0; i < n; i++) cin >> petrol[i];
		for (int i = 0; i < n; i++) cin >> distance[i];

		int *abs_value = new int[n];

		for (int i = 0; i < n; i++)
		{
			abs_value[i] = petrol[i] - distance[i];
		}


		bool flag = true;

		for (int i = 0; i < n; i++)
		{
			if (abs_value[i] > 0)
			{
				if (is_suitable_index(abs_value, n, i))
				{
					flag = false;
					cout << i << " ";
					break;
				}
			}
		}


		if (flag == true)
		{
			cout << -1 << endl;
		}


	}
	return 0;
}
