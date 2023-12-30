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

int largest_power_of_2_less_than_or_equal_to(int n)
{
	int power = 0;
	while (1)
	{
		int num = 1 << power;
		if (num > n) break;
		power++;
	}

	return power - 1;
}

int cnt_set_bit(int n)
{
	wer(n);

	if (n <= 1)
	{
		return n;
	}

	int x = largest_power_of_2_less_than_or_equal_to(n);

	wer(x);

	int ans = 0;

	ans += x * (pow(2, x) / 2);

	//Now for numbers 1 .... (2^x - 1) .. has been calculated

	//for numbers (2^x) ... n ... is to calculate

	//all of them would have one set bit as the most significant one

	ans += n - pow(2, x) + 1;

	//for example n = 11  => x would be 3 ==> 1 ... 7 , calculated;
	//after calucating the most significant bit
	//8 -  1000 => 000
	//9 -  1001 => 001 		=> cnt_set_Bits(3);
	//10 - 1010 => 010
	//11 - 1011 => 011

	ans += cnt_set_bit(n - pow(2, x));

	wer(ans);

	return ans;
}



void update_with_gap(vector<int> &ans , int n)
{
	int cnt = 0;
	bool set = false;
	for (int i = 0; i < ans.size(); i++)
	{
		if (set)
		{
			ans[i] += 1;
			cnt--;
			if (cnt == 0) set = false;
		}
		else
		{
			cnt++;
			if (cnt == n) set = true;
		}
	}
}
vector<int> countBits(int n)
{

	vector<int> ans(n + 1, 0);
	int power = 0;



	while (1)
	{

		int gap = pow(2, power);
		power++;

		if (gap > n) break;

		update_with_gap(ans, gap);
	}

	return ans;

}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;

		vector<int> w = countBits(n);

	}
	return 0;
}
