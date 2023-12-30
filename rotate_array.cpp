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

void rotate(int *a, int l, int r)
{

	int n = r - l + 1;
	int m = n / 2;

	m = m + l;

	int i = l;
	int j = r;
	while (i < m)
	{
		swap(a[i], a[j]);
		i++;
		j--;
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

		int k;
		cin >> k;

		k = k % n;

		rotate(a, 0, n - k - 1);
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		rotate(a, n - k, n - 1);
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		rotate(a, 0, n - 1);
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}




	}
	return 0;
}
