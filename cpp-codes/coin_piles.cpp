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
		int n;
		cin >> n;
		int k;
		cin >> k;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		int i = 0;
		int j = n - 1;
		int op1 = 0;
		while (i < j && (abs(a[i] - a[j]) > k))
		{
			int w = abs(a[i] - a[j]);
			w -= k;
			op1 += w;
			j--;
		}
		i = 0;
		j = n - 1;
		int op2 = 0;
		while (i < j && (abs(a[i] - a[j]) > k))
		{
			op2 += a[i];
			i++;
		}
		cout << min(op1, op2) << endl;

	}
	return 0;
}
