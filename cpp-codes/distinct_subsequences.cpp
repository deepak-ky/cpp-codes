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


int cnt_subseq(string a, string b)
{
	int n = a.length();
	int m = b.length();


	int *dp = new int[m + 1];


	//dp[i] defines how many subsequences are there in "a" for the substring of b from 0 to index i-1
	//dp[m] defines how many subsequences are there in "a" for the substring of b from 0 to index m-1 //
	//which is basically the entire string b


	for (int i = 0; i < (m + 1); i++)
	{
		dp[i] = 0;
	}

	//an empty subsequence is always present
	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = m; j > 0; j--)
		{
			//start traversing from right
			//because  if traversing from the left side
			//a = "abbc" and b = "aabc" // then for index 1 of b same a(index 0) will be used of string a
			if (a[i] == b[j - 1])
			{
				dp[j] = dp[j - 1] + dp[j];
			}
		}
	}


	return dp[m];
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		string a;
		string b;


		cin >> a >> b;


		//find out how many occ subseq's of b are present in a


		cout << cnt_subseq(a, b);

	}
	return 0;
}
