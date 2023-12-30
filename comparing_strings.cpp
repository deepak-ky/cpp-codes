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
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	string a, b;
	cin >> a >> b;
	int len1 = a.length();
	int len2 = b.length();
	int cnt = 0;
	char f[2], s[2];
	int j = 0;
	if (len1 != len2)
	{
		cout << "NO";
	}
	else if (a == b)
	{
		cout << "YES";
	}
	else
	{
		for (int i = 0; i < len1; i++)
		{
			if (a[i] != b[i])
			{
				/*cout << "Here not equal : ";
				cout << a[i] << " -> " << b[i];*/
				cnt++;
				if (cnt > 2)
				{

					cout << "NO";
					return 0;
					break;

				}

				f[j] = a[i];
				s[j] = b[i];
				j++;
			}
		}
		if (cnt == 1) cout << "NO";
		else
		{

			if ((f[0] == s[1]) && (f[1] == s[0]))
			{
				cout << "YES";
			}
			else cout << "NO";
		}

	}


	return 0;
}
