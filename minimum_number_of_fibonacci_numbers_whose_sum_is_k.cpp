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
		int k;
		cin >> k;
		vector<int> fib;
		fib.pb(0);
		fib.pb(1);
		int i = 2;
		int curr_fib_num = fib[i - 1] + fib[i - 2];
		while (curr_fib_num <= k)
		{
			fib.push_back(curr_fib_num);
			i++;
			curr_fib_num = fib[i - 1] + fib[i - 2];
		}


		int cnt = 0;
		while (k != 0)
		{
			auto it = upper_bound(fib.begin(), fib.end() , k);
			it--;
			k = k - *it;
			cout << *it << endl;
			cnt++;
		}

		cout << cnt << endl;

	}
	return 0;
}
