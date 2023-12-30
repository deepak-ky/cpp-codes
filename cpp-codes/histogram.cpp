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

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	asdf(a, n);
	out(a, n);
	stack<int> s;
	int max_area = INT_MIN;
	int i = 0;
	while (i < n)
	{
		wer(i);
		if ((s.empty() == true) || (a[i] >= a[s.top()]))
		{
			s.push(i++);
		}
		else
		{
			int y = s.top();
			wer(a[y]);
			s.pop();
			int ar;
			if (s.empty())
			{
				ar = a[y] * i;
			}
			else
			{

				ar = a[y] * (i - (s.top()) - 1);
			}
			wer(ar);
			if (ar > max_area)
			{
				max_area = ar;
			}
		}
	}
	while (s.empty() == false)
	{

		int y = s.top();
		s.pop();
		int ar;
		if (s.empty())
		{
			ar = a[y] * i;
		}
		else
		{
			ar = a[y] * (i - (s.top()) - 1);
		}
		wer(ar);
		if (ar > max_area)
		{
			max_area = ar;
		}
	}
	cout << endl << "\nMax_area sis : " << max_area;
	return 0;
}
