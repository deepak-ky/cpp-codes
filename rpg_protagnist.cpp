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

class weapon
{
public:
	int weight;
	int qty;
};
int cal(int i, int w_max, int w_min, int exp_one, int cheap_one, int exp_one_qty, int cheap_one_qty)
{
	int ans_local = 0;
	int k4 = w_max / cheap_one;
	i = min(i, k4);  //<-very important step
	ans_local += i;
	cheap_one_qty -= i;
	//what is left of the remaining , what is the maximum number of those that i can take
	w_max -= (i * cheap_one);
	//divide what is left of w_max;

	int k = w_max / exp_one;

	k = min(k, exp_one_qty);
	ans_local += k;
	exp_one_qty -= k;

	//now fill the follower with as much cheap objects as you can
	int k1 = w_min / cheap_one;
	k1 = min(k1, cheap_one_qty);
	ans_local += k1;
	w_min -= k1 * cheap_one;


	int k2 = w_min / exp_one;
	k2 = min(k2, exp_one_qty);
	ans_local += k2;


	return ans_local;

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
		int w, q;
		cin >> w >> q;
		int w_min = min(w, q);
		int w_max = max(w, q);
		weapon w1, w2;

		cin >> w1.qty >> w2.qty;
		cin >> w1.weight >> w2.weight;
		int cheap_one , cheap_one_qty , exp_one , exp_one_qty;
		if (w1.weight >= w2.weight)
		{
			cheap_one = w2.weight;
			cheap_one_qty = w2.qty;
			exp_one = w1.weight;
			exp_one_qty = w1.qty;
		}
		else
		{
			cheap_one = w1.weight;
			cheap_one_qty = w1.qty;
			exp_one = w2.weight;
			exp_one_qty = w2.qty;

		}
		int ans = INT_MIN;
		for (int i = 0; i <= cheap_one_qty; i++)
		{
			int ans_local = cal(i, w_max, w_min, exp_one, cheap_one, exp_one_qty, cheap_one_qty);
			ans = max(ans_local , ans);
		}
		cout << ans << endl;
	}
	return 0;
}
