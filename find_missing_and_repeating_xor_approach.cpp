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
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}


		int final_xor = 0;

		for (int i = 1; i <= n; i++)
		{
			final_xor = final_xor ^ i;
		}

		for (int i = 0; i < n; i++)
		{
			final_xor = final_xor ^  a[i];
		}


		int index_of_set_bit = 0;
		while (final_xor != 0)
		{
			int w = final_xor >> index_of_set_bit;
			if (w & 1 == 1)
			{
				break;
			}
			else index_of_set_bit++;
		}


		vector<int> bit_one_in_arr;
		vector<int> bit_one_in_real;

		for (int i = 1; i <= n; i++)
		{
			int w = i >> index_of_set_bit;
			if (w & 1 == 1)
			{
				bit_one_in_real.push_back(i);
			}
		}

		for (int i = 0; i < n; i++)
		{
			int w = a[i] >> index_of_set_bit;
			if (w & 1 == 1)
			{
				bit_one_in_arr.push_back(a[i]);
			}
		}


		int take_xor = 0;
		for (int i = 0; i < bit_one_in_real.size(); i++)  take_xor = take_xor ^ bit_one_in_real[i];

		for (int i = 0; i < bit_one_in_arr.size(); i++)  take_xor = take_xor ^ bit_one_in_arr[i];


		bool is_present_in_array = false;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == take_xor)
			{
				is_present_in_array = true;
				break;
			}
		}

		if (is_present_in_array)
		{
			cout << "Repeating : " << take_xor << endl;
			cout << "Missing : " << (take_xor ^ final_xor) << endl;
		}
		else
		{
			cout << "Repeating : " << (take_xor ^ final_xor) << endl;
			cout << "Missing : " << take_xor  << endl;

		}


	}
	return 0;
}
