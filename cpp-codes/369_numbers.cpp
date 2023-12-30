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
bool is369(int n)
{
	int thre = 0;
	int sx = 0;
	int nne = 0;
	while (n > 0)
	{
		int r = n % 10;
		if (r == 3)
		{
			thre++;
		}
		else if (r == 6)
		{
			sx++;
		}
		else if (r == 9)
		{
			nne++;
		}
		n = n / 10;
	}

	if ( ((thre) != 0) && ((sx) != 0) && ((nne) != 0) && ((thre) == (sx)) && ((sx) == (nne)) )
	{
		return true;
	}
	else return false;

}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif


	test
	{
		int a, b;
		cin >> a >> b;
		int count = 0;
		for (int i = a; i <= b; i++)
		{
			if (is369(i))
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
