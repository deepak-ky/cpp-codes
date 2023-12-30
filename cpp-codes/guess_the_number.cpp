#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define m                            -1998638045

#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
void apply_operation(int num, int &lb, int &ub, int  w)
{
	if (num == 1) // >=
	{
		lb = max(lb, w);
	}
	else if (num == 2) // >
	{
		lb = max(lb, (w + 1));
	}
	else if (num == 3) // <=
	{
		ub = min(ub, w);
	}
	else if (num == 4) //<
	{
		ub = min(ub, (w - 1));
	}

}
class inp
{
public:
	string sign;
	int value;
	char yn;
};
int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int lb = -1998638045;
	int ub = +1998638045;
	bool flag = true;
	test
	{
		inp a;
		cin >> a.sign;
		cin >> a.value;
		cin >> a.yn;
		int num = -1;
		int w = 0;
		if (a.yn == 'N')
		{
			if (a.sign == ">=")
			{
				apply_operation(4, lb, ub, a.value);
			}
			else if (a.sign == ">")
			{
				apply_operation(3, lb, ub, a.value);

			}
			else if (a.sign == "<=")
			{
				apply_operation(2, lb, ub, a.value);

			}
			else if (a.sign == "<")
			{
				apply_operation(1, lb, ub, a.value);

			}
		}
		else if (a.yn == 'Y')
		{
			if (a.sign == ">=")
			{
				apply_operation(1, lb, ub, a.value);
			}
			else if (a.sign == ">")
			{
				apply_operation(2, lb, ub, a.value);

			}
			else if (a.sign == "<=")
			{
				apply_operation(3, lb, ub, a.value);

			}
			else if (a.sign == "<")
			{
				apply_operation(4, lb, ub, a.value);

			}
		}


	}
	if (ub < lb) cout << "Impossible";
	else cout << lb;

	return 0;
}

