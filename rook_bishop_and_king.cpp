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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	if (r1 == r2 && c1 == c2)
	{
		cout << 0 << " " << 0 << " " << 0;
	}
	else if ((r1 == r2) || (c1 == c2))
	{
		cout << 1 << " " ;
		int w = max((abs(r1 - r2)), (abs(c1 - c2)));
		//wer(w);
		if (w & 1) cout << 0 << " ";
		else cout << 2 << " ";
		cout << w;
	}
	else
	{
		cout << 2 << " ";
		if ((abs(r1 - r2)) == (abs(c1 - c2))) cout << 1 << " ";
		else
		{
			bool flag1 = false;
			bool flag2 = false;
			bool flag3 = false;
			bool flag4 = false;
			if (r1 & 1) flag1 = true;
			if (c1 & 1) flag2 = true;
			if (r2 & 1) flag3 = true;
			if (c2 & 1) flag4 = true;
			bool flag5 = false;
			if ( ((flag1 == true) && (flag2 == true)) ||  ((flag1 == false) && (flag2 == false)))
			{
				flag5 = true;
			}
			bool flag6 = false;
			if ( ((flag3 == true) && (flag4 == true)) ||  ((flag3 == false) && (flag4 == false)))
			{
				flag6 = true;
			}
			if ((flag5 == true && flag6 == true) || (flag5 == false && flag6 == false))
			{
				cout << 2 << " ";
			}
			else
			{
				//cout << "here";
				cout << 0 << " ";
			}
		}


		cout << max((abs(r1 - r2)), (abs(c1 - c2)));

	}

	return 0;
}
