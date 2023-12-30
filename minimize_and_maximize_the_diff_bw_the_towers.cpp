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
		int a[] = {1, 2, 3};
		int n = sizeof(a) / sizeof(int);
		int k = 2;
		sort(a, a + n);
		int miin = a[0];
		int maax = a[n - 1];
		multiset<int> s;
		int ans = a[n - 1] - a[0];
		miin = a[0] + k;
		maax = a[n - 1] - k;
		s.insert(miin);
		s.insert(maax);
		for (int i = 1; i < (n - 1); i++)
		{
			auto sit = s.begin();
			int here_miin = *sit;
			auto eit = s.end();
			eit--;
			int here_maax = *eit;
			int b = a[i];
			int op1 = b - k;
			int op2 = b + k;
			if (op1 >= here_miin && op1 <= here_maax)
			{
				a[i] -= k;
				s.insert(a[i]);
			}
			else if (op2 >= here_miin && op2 <= here_maax)
			{
				a[i] += k;
				s.insert(a[i]);
			}
			else
			{
				int diff_1 = here_maax - op1;
				int diff_2 = op2 - here_miin;
				if (diff_1 <= diff_2)
				{
					a[i] -= k;
					s.insert(a[i]);
				}
				else
				{
					a[i] += k;
					s.insert(a[i]);
				}
			}


		}
		auto sit = s.begin();
		int here_miin = *sit;
		auto eit = s.end();
		eit--;
		int here_maax = *eit;
		cout << min(ans, (here_maax - here_miin));

	}
	return 0;
}
