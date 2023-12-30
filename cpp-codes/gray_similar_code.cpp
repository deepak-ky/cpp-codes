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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
		if (n < 130)
			cin >> a[i];
	}
	if (n >= 130)
	{
		cout << "Yes";
	}
	else
	{
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					for (int l = k + 1; l < n; l++)
					{
						int x = a[i] ^ a[j] ^ a[k];
						if (x == a[l])
						{

							flag = true;
							break;
						}
					}
					if (flag) break;
				}
				if (flag) break;

			}
			if (flag) break;

		}
		if (flag) cout << "Yes";
		else cout << "No";
	}
	cout << endl;
	return 0;
}
