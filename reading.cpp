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
class sample
{
public:
	int value;
	int indices;

};
bool compare(sample s1, sample s2)
{
	return s1.value < s2.value;
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
	int n, k;
	cin >> n >> k;
	sample a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].value;
		a[i].indices = i;
	}
	sort(a, a + n, compare);
	cout << a[n - k].value << endl;
	for (int i = (n - k); i < n; i++)
	{
		cout << a[i].indices + 1 << " ";
	}


	return 0;
}
