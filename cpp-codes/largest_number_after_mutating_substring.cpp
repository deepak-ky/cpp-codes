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



int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n = 10;
		int a[n] = {9, 3, 6, 3, 7, 3, 1, 4, 5, 8};

		string num;
		cin >> num;

		//change where , greater number starting from 1
		int idx = -1;
		//cout << num.length() - 1 << endl;
		while (idx < (num.length() - 1))
		{
			//cout << "here";
			char ch = num[idx + 1];
			//cout << ch << endl;
			int i = ch - '0';
			//cout << i << endl;
			//cout << a[i] << endl;
			//cout << ch - '0' << endl;
			if (a[i] >= (ch - '0'))
			{
				idx++;
			}#include<iostream>
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



			int32_t main()
			{
				init();
				int t = 1;
				//cin>>t;
				while (t--)
				{

				}
				return 0;
			}

			else break;
		}

		for (int i = 0; i <= idx; i++)
		{
			num[i] = a[num[i] - '0'] + 48;
		}

		cout << num << endl;

	}
	return 0;
}
