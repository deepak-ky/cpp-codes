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

int Largest_rectangular_area(int *a, int n)
{
	int *left_nse = new int[n];
	int *right_nse = new int[n];
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++)
	{
		if (s.empty())
		{
			s.push(i);
		}
		else
		{
			while (!s.empty() && a[s.top()]  > a[i])
			{
				right_nse[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}

	while (!s.empty())
	{
		right_nse[s.top()] = n;
		s.pop();
	}

	s.push(n - 1);
	for (int i = n - 2; i >= 0; i--)
	{
		if (s.empty())
		{
			s.push(i);
		}
		else
		{
			while (!s.empty() && a[s.top()] > a[i])
			{
				left_nse[s.top()] = i;
				s.pop();
			}
			s.push(i);
		}
	}

	while (!s.empty())
	{
		left_nse[s.top()] = -1;
		s.pop();
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int area = (right_nse[i] - left_nse[i] - 1) * a[i];
		if (area > ans)
		{
			ans = area;
		}
	}
	out(left_nse, n);
	out(right_nse, n);
	return ans;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int a[] = {6, 2, 5, 4, 5, 1, 6};
		int n = sizeof(a) / sizeof(int);

		cout << "Largest Rectangular area is : " << Largest_rectangular_area(a, n);
	}
	return 0;
}
