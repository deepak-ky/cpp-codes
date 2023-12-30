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

int find_kth_smallest_element(int *a, int *b, int l1, int r1, int l2, int r2, int k)
{
	if (r1 < l1)
	{
		return b[l2 + k - 1];
	}

	if (r2 < l2)
	{
		return a[l1 + k - 1];
	}

	int m1 = l1 + ((r1 - l1) / 2);
	int m2 = l2 + ((r2 - l2) / 2);

	int len1 = m1 - l1 + 1;
	int len2 = m2 - l2 + 1;

	int k_c = len1 + len2;

	if (k_c <= k)
	{
		if (a[m1] < b[m2])
		{
			//Guranteed the element does not lie in l1... m1;
			k = k - (len1);
			return find_kth_smallest_element(a, b, m1 + 1, r1, l2, r2, k);
		}
		else
		{

			//Guranteed the element does not lie in l2...m2;
			k = k - len2;
			return find_kth_smallest_element(a, b, l1, r1, m2 + 1, r2, k);
		}


	}
	else if (k_c > k)
	{
		if (a[m1] < b[m2])
		{
			//Guranteed the element does not lie in the range m2 + 1 ... to r2
			return find_kth_smallest_element(a, b, l1, r1, l2, m2 - 1, k);

		}
		else
		{
			return find_kth_smallest_element(a, b, l1, m1 - 1, l2, r2, k);
		}
	}
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

		int m;
		cin >> m;
		int b[m];
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}


		int k;
		cin >> k;


		int l1 = 0;
		int r1 = n - 1;

		int l2 = 0;
		int r2 = m - 1;

		int w = find_kth_smallest_element(a, b, l1, r1, l2, r2, k);

		cout << w << endl;
	}
	return 0;
}
