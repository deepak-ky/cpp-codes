#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                    cout<<"\n"<<varname(x)<<" here : "<<x
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	vector<int> v1;
	vector<int> v2;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v1.push_back(x);
		v2.push_back(y);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int xmas = INT_MIN;
	int ymas = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			xmas = max(xmas, v1[i]);
			ymas = max(ymas, v2[i]);
			//wer(xmas);
			//wer(ymas);

		}

		else
		{
			int val1 = (abs(v1[i] - v1[i - 1] - 1));
			int val2 = (abs(v2[i] - v2[i - 1] - 1));
			//wer(val1);
			//wer(val2);
			xmas = max(xmas, val1);
			ymas = max(ymas, val2);
			//wer(xmas);
			//wer(ymas);
		}
	}
	//cout << "The answer is : ";
	cout << xmas*ymas;
	return 0;
}
