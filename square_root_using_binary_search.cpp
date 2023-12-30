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



int square_root(int n)
{
	int l = 1;
	int h = n;
	int ans = -1;
	while ( l <= h)
	{
		int m = l + ((h - l) / 2);
		if ( (m * m) <= n)
		{
			ans = m;
			l = m + 1;
		}

		else if ( (m * m) > n)
		{
			h = m - 1;
		}

	}

	return ans;
}

float precision_value(int ans , int s, int precision)
{

	float a = ans;
	float p = precision;   // p number of decimal places
	float n = s;



	float b = 0.1;

	//decreasing p beacuse starting from 0.1 // one decimal place is already taken care of
	p--;
	float copy_a;

	while (p >= 0)
	{
		for (float j = 0; j <= (b * 10); j += b)
		{
			float c = a;
			c = c + j;

			if ( (c * c ) <= n)
			{
				copy_a = c;
			}
			else
			{
				break;
			}
		}
		a = copy_a;
		//Here decimal digits will be keep on adding to a;
		b = b / 10;
		p--;
	}

	return a;


}





int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int precision = 3;
		for (int i = 1; i <= 65e; i++)
		{
			int ans = square_root(i);
			cout << i << " : ";
			if (ans * ans == i)
			{
				cout << ans << " * " << ans << endl;
			}
			else
			{
				cout << precision_value(ans, i , precision) << endl;
			}
		}


	}
	return 0;
}
