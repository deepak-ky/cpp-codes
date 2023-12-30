#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl

int lcs_length(string a, string b, int n, int m)
{
	int  dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				if (a[i - 1] == b[j - 1])
				{
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
}
string print_lcs(string a, string b, int n, int m)
{
	int  dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				if (a[i - 1] == b[j - 1])
				{
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
			}
		}
	}
	int index = dp[n][m];
	string lcs = "";
	int i = n;
	int j = m;
	index--;
	while (i > 0 && j > 0)
	{
		if (a[i - 1] == b[j - 1])
		{
			lcs += a[i - 1];
			index--;
			i--;
			j--;
		}
		else if (dp[i - 1][j] >= dp[i][j - 1])
		{
			i--;
		}
		else {
			j--;
		}
	}
	reverse(lcs.begin(), lcs.end());
	return lcs;
}
int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	string a, b;
	cin >> a >> b;
	string l = print_lcs(a, b, a.length(), b.length());



	string ans = "";

	int i = 0;
	char target = l[i];
	int len = l.length();


	//prefix
	int loc_in_a = 0;
	int loc_in_b = 0;
	while (a[loc_in_a] != target)
	{
		loc_in_a++;
	}
	while (b[loc_in_b] != target)
	{
		loc_in_b++;
	}
	string pre_a = a.substr(0, loc_in_a - 0);
	string pre_b = b.substr(0, loc_in_b - 0);

	ans += pre_a;
	ans += pre_b;

	ans += target;




	//inside the lcs
	i++;
	target = l[i];
	int new_loc_in_a = loc_in_a;
	int new_loc_in_b = loc_in_b;
	while (i < len)
	{
		new_loc_in_a++;
		new_loc_in_b++;

		while (a[new_loc_in_a] != target)
		{
			new_loc_in_a++;
		}
		while (b[new_loc_in_b] != target)
		{
			new_loc_in_b++;
		}
		loc_in_a++;
		loc_in_b++;
		string in_a = a.substr(loc_in_a, new_loc_in_a - loc_in_a);
		string in_b = b.substr(loc_in_b, new_loc_in_b - loc_in_b);
		ans += in_a;
		ans += in_b;
		ans += target;

		loc_in_a = new_loc_in_a;
		loc_in_b = new_loc_in_b;



		i++;
		target = l[i];
	}





	//suffix // after lcs // ending part

	string pres_a = a.substr(loc_in_a + 1 , a.length() - loc_in_a);
	string pres_b = b.substr(loc_in_b + 1, b.length() - loc_in_b);
	ans += pres_a;
	ans += pres_b;


	cout << ans << endl;



	/*cout << ans;
	cout << endl;
	cout << a.length() + b.length() - lcs_length(a, b, a.length(), b.length()) << endl;*/

	return 0;
}
