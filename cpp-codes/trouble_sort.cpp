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
int find_the_index(int *a, int last_index)
{
	int max_value = a[0];
	int final_index = 0;
	for (int i = 1; i <= last_index; i++)
	{
		if (a[i] >= max_value)
		{
			max_value = a[i];
			final_index = i;
		}
	}
	return final_index;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	int b[n];
	asdf(a, n);
	asdf(b, n);

	int flag = 0;
	int last_index = (n - 1);
	while (last_index >= 0)
	{
		int idx = find_the_index(a, last_index);
		wer(idx);
		int w = 0;
		if (idx != last_index)
		{
			if (b[idx] != b[last_index])
			{
				swap(a[idx], a[last_index]);
				swap(b[idx], b[last_index]);
			}
			else
			{
				flag = 1;
				break;
			}
		}
		out(a, n);
		out(b, n);
		last_index--;
	}
	if (flag == 1)
	{
		cout << "No";
	}
	else cout << "Yes";
	return 0;
}
