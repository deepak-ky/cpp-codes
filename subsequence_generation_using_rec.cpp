#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout/*<<"\n"*/<<varname(x)<<" here : "<<x<<"\n"
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

void print_subsequence(string s, int idx, string a)
{
	if (idx == s.length())
	{
		cout << a << endl;
		return;
	}
	print_subsequence(s, idx + 1, a + s[idx]);
	print_subsequence(s, idx + 1, a);


	return;

}

void print_subsequence_2(char *in, char *out, int i, int j)
{

	if (in[i] == '\0')
	{
		out[j] = '\0';

		cout << out << endl;
		return;
	}
	out[j] = in[i];
	print_subsequence_2(in, out, i + 1, j + 1);
	print_subsequence_2(in, out, i + 1, j);
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
		//print_subsequence(s, 0, "");
		cout << endl;
		char in[] = "abc";
		char out[4];
		print_subsequence_2(in, out, 0, 0);
	}
	return 0;
}

