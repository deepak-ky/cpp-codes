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
		int sum_of_digits;
		int num_of_digits;
		cin >> sum_of_digits;
		cin >> num_of_digits;


		if (num_of_digits * 9 < sum_of_digits)
		{
			cout << -1 << endl;
		}
		else
		{
			string ans = "";
			num_of_digits--;
			bool first_digit = true;
			int check;
			while (num_of_digits != 0)
			{
				if (first_digit == true)
				{
					check = 1;
					first_digit = false;
				}
				else check = 0;
				while (1)
				{
					if (num_of_digits * 9 >= (sum_of_digits - check))
					{
						string w = to_string(check);
						ans += w;
						break;
					}
					else
					{
						check++;
					}
				}
				sum_of_digits -= check;
				num_of_digits--;

			}

			string w = to_string(sum_of_digits);
			ans += w;


			cout << ans << endl;

		}
	}
	return 0;
}
