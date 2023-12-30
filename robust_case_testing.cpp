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
		cout << "Enter the number of variables : ";
		cin >> n;

		cout << "Enter the range of the input : \n";
		int l_limit;
		int u_limit;
		cout << endl;
		cin >> l_limit >> u_limit;
		if (u_limit <= l_limit)
		{
			cout << "Please enter valid inputs";
		}
		else
		{
			int mid = l_limit + ((u_limit - l_limit) / 2);
			cout << "The total number of test cases are : 6*n+1 : " << 6 * n + 1 << endl;
			int cnt = 0;
			int a[6];
			a[0] = l_limit - 1;
			a[1] = l_limit;
			a[2] = l_limit + 1;
			a[3] = u_limit - 1;
			a[4] = u_limit;
			a[5] = u_limit + 1;
			int variable = 1;
			cout << "T" << "\t";
			for (int i = 0; i < n; i++)
			{
				char ch = 65 + i;
				cout << ch << "\t";
			}
			cout << "Output";
			cout << endl;
			while (variable <= n)
			{
				cout << cnt + 1 << "\t";
				int maxi = a[cnt % 6];
				for (int i = 0; i < n; i++)
				{
					if (cnt / 6 == i)
					{
						cout << a[cnt % 6] << "\t";
					}
					else
					{
						maxi = max(maxi, mid);
						cout << mid << "\t";
					}

				}
				int r = cnt % 6;
				if (r == 0 || r == 5)
				{
					cout << "Invalid Output";
				}
				else cout << maxi;
				cout << "\t";
				cout << endl;
				cnt++;
				if (cnt % 6 == 0)
				{
					variable++;
				}

			}

			cout << cnt + 1 << "\t";
			for (int k = 0; k < n + 1; k++)
			{
				cout << mid << "\t";
			}
			cout << endl;



		}
	}
	return 0;
}
