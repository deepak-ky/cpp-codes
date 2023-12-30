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
		n = (2 * n) + 2;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		int w = n;

		int initial_xor = 0;
		for (int i = 0; i < n; i++)
		{
			initial_xor = initial_xor ^ a[i];
		}

		wer(initial_xor);


		int first_bit_set_index = 0;
		while (1)
		{
			int u = initial_xor >> first_bit_set_index;
			if (u & 1) break;
			first_bit_set_index++;
		}

		wer(first_bit_set_index);




		int new_xor = 0;
		for (int i = 0; i < n; i++)
		{
			int u = a[i] >> first_bit_set_index;
			if (u & 1)
			{
				wer(a[i]);
				new_xor = new_xor ^ a[i];
			}
		}




		for (int i = 0; i < n; i++)
		{
			new_xor = new_xor ^ a[i];
		}

		cout << new_xor << endl;
		cout << (new_xor ^ initial_xor) << endl;

	}
	return 0;
}
