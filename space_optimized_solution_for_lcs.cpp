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

int lcs(string s1, string s2)
{
	int n  = s1.length();
	int m  = s2.length();

	int upper_row[m + 1];
	int lower_row[m + 1];

	for (int i = 0; i < m + 1; i++)
	{
		upper_row[i] = 0;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			if (j == 0)
			{
				lower_row[j] = 0;
			}
			else
			{
				if (s1[i - 1] == s2[j - 1])
				{
					lower_row[j] = 1 + upper_row[j - 1];
				}
				else
				{
					lower_row[j] = max(lower_row[j - 1], upper_row[j]);
				}
			}
		}

		for (int k = 0; k < m + 1; k++)
		{
			upper_row[k] = lower_row[k];
		}
	}

	return upper_row[m];

}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		cout << lcs("ABCDGH", "AEDFHR");
	}
	return 0;
}
