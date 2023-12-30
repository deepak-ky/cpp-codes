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
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		string a;
		cin >> a;

		string b;
		cin >> b;
		if (n == 1)
		{
			if (a == b)
			{	yes;
			}
			else
			{no;}
		}
		else if (a.compare(b) == 0)
		{
			yes;
		}
		else
		{

			bool flag = false;
			int a_zero = 0;
			int a_one = 0;
			int last_value = -1;
			for (int i = 0; i < n; i++)
			{
				if (a[i] == '0')
				{
					a_zero++;
				}
				else a_one++;

				if (a_zero == a_one)
				{
					last_value++;
					string w = a.substr(last_value, i - last_value + 1);
					int len = i - last_value + 1;
					int mis_matches = 0;
					for (int j = last_value; j <= i; j++)
					{
						if (a[j] != b[j])
						{
							mis_matches++;
						}
					}

					if (mis_matches != len && mis_matches != 0)
					{
						flag = true;
						break;
					}

					last_value = i;
					a_one = 0;
					a_zero = 0;



				}


			}
			if (a_zero != 0 || a_one != 0)
			{
				last_value++;

				string w = a.substr(last_value, (n) - last_value);
				int mis_matches = 0;
				for (int j = last_value; j <= n - 1; j++)
				{
					if (a[j] != b[j])
					{
						mis_matches++;
					}
				}

				if (/*mis_matches != len && */mis_matches != 0)
				{
					flag = true;

				}



			}


			if (flag)
			{
				no;
			}
			else yes;


		}
	}
	return 0;
}
