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

string ans;

void form_the_biggest_number(int idx, string s, string a, int k)
{

	if (k == 0 || idx == s.length())
	{
		// wer(s);
		ans = max(ans, s);

		return;
	}

	if (s[idx] == a[idx])
	{
		form_the_biggest_number(idx + 1, s, a, k);
		return;
	}
	else
	{
		int current_index = idx;
		int current_number = s[idx] - '0';
		int required_number = a[idx] - '0';

		for (int i = idx + 1; i < s.length(); i++)
		{
			if (s[i] - '0' == required_number)
			{
				swap(s[i], s[idx]);
				form_the_biggest_number(idx + 1, s, a, k - 1);
				//This is about not changing the original string

				swap(s[i], s[idx]);
			}

		}

	}

	return;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		string s;
		cin >> s;
		cout << s << endl;

		int k;
		cin >> k;



		string a = s;
		sort(a.begin(), a.end(), greater<int>());

		ans = s;

		form_the_biggest_number(0, s, a, k);


		wer(ans);









	}
	return 0;
}
