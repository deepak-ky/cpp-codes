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



void solve(string a)
{
	int n = a.length();
	bool dp[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = false;
		}
	}

	//a substring of length 1 will always be a palindrome

	for (int i = 0; i < n; i++)
	{
		dp[i][i] = true;
	}


	//length of largest substring
	int large_len = 1;
	string largest = "";
	largest += a[0];


	//cnt of substrings;
	int cnt = 0;
	for (auto x : a)
	{
		cout << x << endl;
	}
	cnt += a.length();



	//a substring of length 2 will be a palindrome only if the extremites are equal
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == a[i + 1])
		{
			dp[i][i + 1] = true;
			cnt++;
			cout << a[i] << a[i + 1] << endl;

			if (large_len != 2)
			{
				large_len = 2;
				string g = a.substr(i, 2);
				largest = g;
			}
		}
	}




	int level = n - 2;
	while (level >= 0)
	{
		int k = n - level;
		for (int i = 0; i < level; i++)
		{
			int j = i + k;
			if (a[i] == a[j] && (dp[i + 1][j - 1] == true))
			{
				dp[i][j] = true;


				//1. Increase the count
				cnt++;

				//2. Display the string
				string p = a.substr(i, j - i + 1);
				cout << p << endl;


				//3. Largest work
				if ((j - i + 1) > large_len)
				{
					largest = p;
					large_len = (j - i + 1);
				}


			}
		}
		level--;
	}


	cout << endl << "Total Palindromic Substrings : " << cnt << endl;

	cout << endl << "Largest String : " << largest << endl;

	cout << endl << "Largest length : " << large_len << endl;


	return;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		string a;
		cin >> a;


		//1.Find the number of palindromic Substrings
		//2.Display all the palindromic substrings
		//2.Find the largest palindromic substring
		//3.Find the length of largest palindromic substring

		solve(a);
	}
	return 0;
}
