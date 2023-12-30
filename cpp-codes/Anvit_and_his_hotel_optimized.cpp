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
bool checkit(int arrival[], int departure[], int mid, int n)
{
	for (int i = 0; (i + mid) < n; i++)
	{
		if ( (arrival[i + mid] < departure[i]))
		{
			return false;
		}
	}
	return true;
}
class g
{
public:
	int arrival;
	int duration;
};
bool compare(g a, g b)
{
	return a.arrival < b.arrival;
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
	g guest[n];
	for (int i = 0; i < n; i++)
	{
		cin >> guest[i].arrival;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> guest[i].duration;
	}
	sort(guest, guest + n, compare);
	int arrival[n], duration[n], departure[n];
	for (int i = 0; i < n; i++)
	{
		arrival[i] = guest[i].arrival;
		duration[i] = guest[i].duration;
		departure[i] = guest[i].arrival + guest[i].duration;
	}

	int s = 1;
	int e = n;
	int ans = INT_MAX;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		wer(mid);
		if (mid == 9)
		{
			cout << endl << "s is : " << s;
			cout << endl << "e is : " << e;
		}
		if (checkit(arrival, departure, mid, n))
		{	cout << "\ngetting executed : ";
			ans =  mid;
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		}
	}
	cout << endl << "\nThe ans is : " << ans;


	return 0;
}
