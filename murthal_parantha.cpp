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
bool can_cook(int p, int m, int n, int *a)
{
	int parata = 0;
	for (int i = 0; i < n; i++)
	{
		int rank = a[i];
		int cook_time = a[i];
		int j = 2;
		while (cook_time <= m)
		{
			parata++;
			cook_time = cook_time + j * rank;
			j++;
		}
		j = 2;
		if (parata >= p)
		{
			return true;
		}

	}

	return false;
}
int min_time(int p, int l, int h, int *a, int n)
{
	int ans = h;
	while (l <= h)
	{
		int m = l + ((h - l) / 2);
		if (can_cook(p, m, n, a))
		{

			ans = m;
			h = m - 1;
		}
		else
		{
			l = m + 1;
		}

	}
	return ans;
}

int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		int p;
		cin >> p;




		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int max_time = *max_element(a, a + n);
		sort(a, a + n);

		int w = (p * (p + 1));
		w = w / 2;

		w = w * max_time;




		cout << min_time(p, 0, w, a, n) << endl;


	}
	return 0;
}
