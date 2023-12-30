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

string longest_palidromic_substring(string a)
{
	int max_length = 1;
	string ans = "";
	ans += a[0];
	int n = a.length();

	for (int i = 1; i < n; i++)
	{
		//First find out all the odd length palindromes
		int low = i;
		int high = i;
		while (low >= 0 && high < n && (a[low] == a[high]) )
		{
			int curr_len = high - low + 1;
			if (curr_len > max_length)
			{
				max_length = curr_len;
				ans = a.substr(low, curr_len);
			}
			low--;
			high++;
		}



		//Find out all the even length palindromes

		low = i - 1;
		high = i;
		while (low >= 0 && high < n && (a[low] == a[high]) )
		{
			int curr_len = high - low + 1;
			if (curr_len > max_length)
			{
				max_length = curr_len;
				ans = a.substr(low, curr_len);
			}
			low--;
			high++;
		}
	}



	return ans;


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

		cout << longest_palidromic_substring(a);

	}
	return 0;
}
