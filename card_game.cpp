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
int return_ind(char *order, char ch)
{
	for (int i = 0; i < 9; i++)
	{

		if (ch == order[i])
		{
			return i;
		}
	}

}
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	char order[] = {'6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	char ch;
	cin >> ch;
	string s1;
	string s2;
	cin >> s1 >> s2;
	if (s1[1] == ch)
	{
		if (s2[1] != ch)
		{

			cout << "YES";
		}
		else
		{
			int w = return_ind(order, s1[0]);
			int w1 = return_ind(order, s2[0]);
			if (w > w1)
			{
				cout << "YES";
			}
			else
			{ cout << "NO";}
		}

	}
	else if (s2[1] == ch)
	{

		cout << "NO";
	}
	else
	{
		if (s1[1] != s2[1])
		{

			cout << "NO";
		}
		else
		{
			int w = return_ind(order, s1[0]);
			int w1 = return_ind(order, s2[0]);
			if (w > w1)
			{
				cout << "YES";
			}
			else cout << "NO";

		}
	}

	return 0;
}
