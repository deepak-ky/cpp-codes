#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : \n"<<x
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : \n";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define pb                           push_back

class number
{
public:
	int value;
	int index;
};
bool compare(number n1 , number n2)
{
	if (n1.value <= n2.value)
	{
		return true;
	}
	else return false;
}

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	test
	{
		int n, k;
		cin >> n;
		cin >> k;
		//number of variables with half value
		int half_value_variables  = 0;
		for (int i = 0; i < n; i++)
		{
			int w;
			cin >> w;
			int r;
			if ( k % 2 == 0 && w == k / 2)
			{
				half_value_variables++;
				r = (half_value_variables) % 2;
				//in this case it will keep alternating between the two
			}
			else if ( 2 * w < k)
			{
				r = 0;
			}
			else r = 1;
			cout << r << " ";
		}
		cout << endl;
	}
	return 0;
}
