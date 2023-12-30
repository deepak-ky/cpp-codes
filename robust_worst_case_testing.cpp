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
		int l_limit;
		cin >> l_limit;
		int h_limit;
		cin >> h_limit;
		int a[7];
		int mid = l_limit + ((h_limit - l_limit) / 2);
		a[0] = l_limit - 1;
		a[1] = l_limit;
		a[2] = l_limit + 1;
		a[3] = mid;
		a[4] = h_limit - 1;
		a[5] = h_limit;
		a[6] = h_limit + 1;
		cout << "T" << "\t" << "A" << "\t" << "B" << "\t" << "C" << "\t\t" << "Output" << "\n";
		int cnt = 1;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				for (int k = 0; k < 7; k++)
				{
					cout << cnt << "\t" <<  a[i] << "\t" << a[j] << "\t" << a[k] << "\t\t";
					if (i == 0 || j == 0 || k == 0 || i == 6 || j == 6 || k == 6)
					{
						cout << "Invalid Input";
					}
					else cout << max(a[i], max(a[j], a[k]));
					cnt++;
					cout << endl;
				}
			}
		}
	}
	return 0;
}
