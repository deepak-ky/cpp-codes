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
vector<int> convert(int c)
{
	//wer(c);
	vector<int> digit;
	while (c != 0)
	{
		int r = c % 10;
		digit.push_back(r);
		c = c / 10;
	}

	if (digit.size() == 0) digit.push_back(c);
	reverse(digit.begin(), digit.end());
	/*fr (auto x : digit)
	{
		cout << x << " ";
	}*/
	return digit;
}
int solve(vector<int> a, int b, int c)
{
	int a_size = a.size();
	if (a.size() == 0)
	{
		return 0;
	}
	vector<int> digits_of_c;
	digits_of_c = convert(c);
	/*for (auto x : digits_of_c)
	{
		cout << x << " ";
	}
	cout << endl;*/
	if (b > digits_of_c.size()) //agar c hee ek digit ka number hain or 2 digit ke number bananbe hani toh nahi ban sakte kyunk i kabhi kam hee nahi hoga
	{
		return 0;
	}
	if (b < digits_of_c.size()) //agar c  2 digit ka number hain or or ek digit ka number oth saare hee nuber kam honge
	{
		if (a[0] == 0 && b != 1)
		{
			//cout << "here";

			return ((a_size - 1) * pow(a_size, (b - 1)));
		}
		else return pow(a_size, b);
	}
	else
	{
		int dp[b + 1] = {0};
		//dp[i] denotes the total number of numbers of length i that can be made that are less than first i digits of c
		//therefore dp[b] will deonte the total number of length b that can be made that are less than first b digits of c that is c only
		int lower[11] = {0};//there might be some numbers which are present in c but not present in a eg c : 456 and a : 1,2,3 lower[4] = 3

		for (int i = 0; i < a_size; i++)
		{
			lower[a[i] + 1] = 1;
		}
		for (int i = 1; i <= 11; i++)
		{
			lower[i] = lower[i - 1] + lower[i];
		}

		dp[0] = 0;
		bool flag = true;

		//for all the numbers whose first(i-1) is less than first(i-1) of k , we can put any digit at the ith index dp[i] = dp[i-1] * a_size;
		//for all the numbers whose first(i-1) is same than first(i-1) of k , we can only put digits which are less than digit[i];


		for (int i = 1; i <= b; i++)
		{
			int lb = lower[digits_of_c[i - 1]];
			wer(lb);
			dp[i] = dp[i - 1] * a_size;

			if (i == 1 && a[0] == 0 && b != 1)
			{
				lb = lb - 1;
			}
			if (flag)
			{
				dp[i] += lb;
			}

			auto it = find(a.begin(), a.end(), digits_of_c[i - 1]);
			bool flag1;
			if (it != a.end())
			{
				flag1 = true;
			}
			else flag1 = false;

			flag = flag & flag1;
		}

		return dp[b];
	}
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
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		a.push_back(w);
	}
	int b;
	int c;
	cin >> b >> c;
	cout << solve(a, b, c);
	return 0;
}
