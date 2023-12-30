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
#define s                            second

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

bool markAndSave(vector<int> &bits,int w)
{
	bool flag = false;

	for(int j=0;j<32;j++)
	{
		int ww = w >> j;
		if(ww & 1)
		{
			if(bits[j] == 1)
			{
				flag = true;
				break;
			}
		 	bits[j] = 1;
		}
	}
	
	if(flag == false)
	{
		return true;
	}

    bits.clear();
	for(int j=0;j<32;j++)
	{
		int ww = w >> j;
		if(ww & 1)
		{
		 	bits[j] = 1;
		}
	}
	return false;
}


int32_t main()
{
	init();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		vector<int> a = {3,1,5,11,13};
		for(auto x : a) cout << x << " ";
		a = vector<int>(5,0);
		for(auto x : a) cout << x << " ";

		/*int n = a.size();
		vector<int> bits(32,0);
		vector<int> dp(n,0);
		dp[0] = 1;
		int ans = 1;
		bool b1 = markAndSave(bits,a[0]);

		for(int i=1;i<n;i++){
			int w = a[i];
			bool b = markAndSave(bits,w);
			if(b){
				dp[i] = 1 + dp[i-1];
			}else{
				dp[i] = 1;
			}
			ans = max(ans,dp[i]);
		}

		cout << ans << endl;*/


	}
	return 0;
}
