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
#define s                            second

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

unordered_map<int, string> mp;
void initialize_map()
{
	mp[0] = "zero";
	mp[1] = "one";
	mp[2] = "two";
	mp[3] = "three";
	mp[4] = "four";
	mp[5] = "five";
	mp[6] = "six";
	mp[7] = "seven";
	mp[8] = "eight";
	mp[9] = "nine";
}



void display(string a, int idx, int n)
{
	if (idx >= n)
	{
		return;
	}
	char ch = a[idx];
	int w = ch - '0';
	cout << mp[w] << " ";
	display(a, idx + 1, n);
}

void display2(int a)
{
	//base condition
	if (a == 0)
	{
		return;
	}
	//display
	display2(a / 10);
	int w = a % 10;
	cout << mp[w] << " ";

}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		initialize_map();
		string a = "2048";
		int n = a.length();
		display(a, 0, n);

		cout << endl;
		int b = 2048;
		display2(b);
	}
	return 0;
}
