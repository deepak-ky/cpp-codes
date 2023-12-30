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

int number_of_ops(string a, string b)
{
	int n = a.length();
	int res = 0;
	int i = n - 1;
	int j = n - 1;
	while (i >= 0)
	{
		if (a[i] == b[j])
		{
			i--;
			j--;
		}
		else
		{
			i--;
			res++;
		}
	}

	return res;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		string a, b;
		cin >> a >> b;
		string a_copy = a;
		sort(a_copy.begin(), a_copy.end());
		string b_copy = b;
		sort(b_copy.begin(), b_copy.end());
		if (a_copy.compare(b_copy) == 0)
		{
			cout << number_of_ops(a, b);
		}
		else
		{
			no;
		}


	}
	return 0;
}
