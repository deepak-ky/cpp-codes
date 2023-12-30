#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl



int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);
	bool found = false;
	for (int i = 0; i < n - 1; i++)
	{
		int l = i + 1;
		int r = n - 1;
		while (l < r)
		{
			int w = a[i] + a[l] + a[r];
			if (w == 0)
			{
				cout << a[i] << " " << a[l] << " " << a[r] << endl;
				found = true;
			}
			else if (w < 0)
			{
				l++;
			}
			else r--;
		}
	}
	if (found) cout << "true";
	else cout << "false";
	return 0;
}
