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

int find(int *a, int l, int h, int key)
{
	int ans = -1;
	while (l <= h)
	{
		int m = l + ((h - l) / 2);
		if (a[m] > key)
		{
			ans = m;
			l = m + 1;
		}
		else if (a[m] == key)
		{
			h = m - 1;
		}
		else
		{
			h = m - 1;
		}
	}
	return ans;
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
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}


		int i = n - 2;
		while (i >= 0)
		{
			if (a[i] < a[i + 1])
			{
				break;
			}
			else i--;
		}
		if (i == -1)
		{
			//The array is in descending order
			sort(a, a + n);
		}
		else
		{
			//we have to find the index of the smallest largest number than the
			//current index in the i+1 to (n-1)
			//we will use binary search
			int index = find(a, i + 1, n - 1, a[i]);

			swap(a[index], a[i]);
			sort(a + (i + 1), a + n);

		}

		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}

	}
	return 0;
}
