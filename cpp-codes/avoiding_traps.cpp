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

const int N = 100005;
int is_prime[N];
int prime_cnt[N];

void fill_array()
{
	memset(is_prime, 0, sizeof(is_prime));

	is_prime[0] = is_prime[1] = 0;
	is_prime[2] = 1;

	for (int i = 3; i < N; i += 2)
	{
		is_prime[i] = 1;
	}

	for (int i = 3; i < N; i += 2)
	{
		if (is_prime[i] == 1)
		{
			for (int j = i * i; j < N; j += i)
			{
				is_prime[j] = 0;
			}
		}
	}

	prime_cnt[0] = 0;
	prime_cnt[1] = 0;
	for (int i = 2; i < N; i++)
	{
		prime_cnt[i] = prime_cnt[i - 1] + is_prime[i];
	}
}

int r1, r2;

bool check_special(int i)
{
	if ((prime_cnt[i] * r2 ) >= (r1 * i))
	{
		return true;
	}
	else return false;
}


/*int dp[N];

int find_minimum_steps(int idx, string ch, int n)
{
	//wer(idx);

	if (idx > n)
	{
		return INT_MAX;
	}

	if (idx == (n))
	{
		if (ch[idx - 1] == '#')
			return 0;
		else
			return INT_MAX - 1;
	}

	if (dp[idx] != -1)
	{
		return dp[idx];
	}

	if (ch[idx - 1] == '*')
	{
		return dp[idx] = INT_MAX - 1;
	}

	//from the particular point
	int op1 = INT_MAX - 1;
	if (idx + 1 <= n)
		op1 = 1 + find_minimum_steps(idx + 1, ch,  n);

	int op2 = INT_MAX - 1;
	if (idx + 1 <= n)
		op2 = 1 + find_minimum_steps(idx + 2, ch,  n);

	int op3 = INT_MAX;

	if (check_special(idx) && (idx + prime_cnt[idx] <= n))
	{
		op3 = 1 + find_minimum_steps(idx + prime_cnt[idx], ch, n);
	}

	return dp[idx] = min(op1, min(op2, op3));
}*/

int32_t main()
{
	init();
	fill_array();
	int t = 1;
	cin >> t;
	while (t--)
	{
		//memset(dp, -1, sizeof(dp));
		int r11, r22;
		cin >> r11 >> r22;

		r1 = r11;
		r2 = r22;

		int n;
		cin >> n;

		string ch;
		cin >> ch;


		/*
				int w = find_minimum_steps(1, ch,  n);


				if (w == INT_MAX)
				{
					cout << "No Way!" << endl;
				}
				else cout << w << endl;
		*/


		int dp[n + 1];

		for (int i = 0; i < n + 1; i++)
		{
			dp[i] = INT_MAX;
		}

		if (ch[0] == '*' || ch[n - 1] == '*')
		{
			cout << "No way!" << endl;
		}
		else
		{

			dp[0] = 0;
			dp[1] = 0;


			for (int i = 1; i <= n; i++)
			{
				if (ch[i - 1]  == '#' && dp[i] != INT_MAX)
				{
					if (i + 1 <= n && ch[i] == '#')
					{
						dp[i + 1] = min(dp[i + 1], dp[i] + 1);
					}

					if (i + 2 <= n && ch[i + 1] == '#')
					{
						dp[i + 2] = min(dp[i + 2] , dp[i] + 1);
					}

					if (check_special(i) == true && (i + prime_cnt[i] <= n) && ch[i + prime_cnt[i] - 1] == '#')
					{
						dp[i + prime_cnt[i]] = min(dp[i + prime_cnt[i]] , dp[i] + 1);
					}
				}
			}

			//out(dp, n + 1);

			if (dp[n] != INT_MAX)
			{
				cout << dp[n] << endl;
			}
			else cout << "No way!" << endl;
		}



	}
	return 0;
}
