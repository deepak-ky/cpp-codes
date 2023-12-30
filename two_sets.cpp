#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<endl<<varname(x)<<" here : "<<x<<"\n"
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back
#define yes                          cout << "YES" << endl;
#define no                           cout << "NO"  << endl;
#define f                            first
#define s                            second

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
		int w = (n * (n + 1) ) / 2;
		if (w & 1)
		{
			no;
		}
		else
		{
			yes;
			int r = w / 2;
			vector<int> a;
			a.pb(0);
			for (int i = 1; i <= n; i++)
			{
				a.pb(i);
			}
			//if it is not divisible by n then it would be divisible by n+1
			// make r in both the cases
			if (r % n == 0)
			{

				unordered_set<int> s;
				s.insert(a[a.size() - 1]);
				int sum1 = n;
				int i = 1;
				int j = a.size() - 2;
				while (sum1 != r)
				{
					sum1 += a[i] + a[j];
					s.insert(a[i]);
					s.insert(a[j]);
					i++;
					j--;
				}
				cout << s.size() << endl;
				for (auto x : s)
				{
					cout << x << " ";
				}
				cout << endl << n - s.size() << endl;
				for (int i = n; i >= 1; i--)
				{
					if (s.find(i) == s.end())
					{
						cout << i << " ";
					}
				}
			}
			else if (r % (n + 1) == 0)
			{
				unordered_set<int> s;
				int sum1 = 0;
				int i = 1;
				int j = a.size() - 1;
				while (sum1 != r)
				{
					sum1 += a[i] + a[j];
					s.insert(a[i]);
					s.insert(a[j]);
					i++;
					j--;
				}
				cout << s.size() << endl;
				for (auto x : s)
				{
					cout << x << " ";
				}
				cout << endl << n - s.size() << endl;
				for (int i = n; i >= 1; i--)
				{
					if (s.find(i) == s.end())
					{
						cout << i << " ";
					}
				}
			}


		}

	}
	return 0;
}
