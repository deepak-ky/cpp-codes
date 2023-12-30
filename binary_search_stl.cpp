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
		//         0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
		int a[] = {1, 2, 2, 3, 4, 4, 4, 5, 6, 8, 8};
		int n = sizeof(a) / sizeof(int);
		bool flag = binary_search(a, a + n, 8);
		if (flag)
		{
			cout << "Present\n";
			auto lb = lower_bound(a, a + n, 9);
			cout << "lb is : " << lb - a << endl;

			auto ub = upper_bound(a, a + n, 9);

			cout << "ub is : " << ub - a << endl;

			cout << "freq of 8 is : " << ub - lb << endl;

			for (auto it = lb; it != ub; it++)
			{
				cout << *it << " ";
			}
		}
		else cout << "Absent";
	}
	return 0;
}
