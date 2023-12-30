#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
class point
{
public:
	int x;
	int y;
};
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
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
	//point p[n];
	vector<pair<float, float> >p;
	for (int i = 0; i < n; i++)
	{
		float f, s;
		cin >> f >> s;
		p.push_back(make_pair(f, s));
	}
	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = (i + 1); j < n; j++)
		{
			cout << "\nThe pair : " << p[i].first << " " << p[i].second << ":" << p[j].first << " " << p[j].second;
			float ff;
			ff = (p[i].second - p[j].second) / (p[i].first - p[j].first);
			cout << "\nThe slope is : " << ff;
		}
	}
	return 0;
}
