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

class Item
{
public:
	int value;
	int weight;
};

class compare
{
public:
	bool operator()(Item const& i1 , Item const& i2)
	{


		double d1 = (double)i1.value / (double)i1.weight;
		double d2 = (double)i2.value / (double)i2.weight;

		if (d1 < d2)
		{
			return true;
		}
		else if (d1 == d2)
		{
			//uspe depend karna chaiye jiska weight zyada hain
			if (i1.weight < i2.weight)
			{
				return true;
			}
			else return false;
		}
		else return false;
	}
};

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;

		int w;
		cin >> w;

		double W = (double)w;

		Item Items[n];

		for (int i = 0; i < n; i++)
		{
			cin >> Items[i].value;
			cin >> Items[i].weight;

		}



		priority_queue<Item, vector<Item>, compare> pq;


		for (int i = 0; i < n; i++)
		{
			pq.push(Items[i]);
		}


		double ans = 0;
		double current_capacity = 0;

		while (!pq.empty() && current_capacity < W)
		{
			Item i = pq.top();
			pq.pop();

			double vpw = (double)i.value / (double)i.weight;
			double max_cap = i.weight;

			double to_take_cap = min(max_cap, (W - current_capacity));

			ans += (to_take_cap * vpw);
			current_capacity += to_take_cap;
		}


		cout << ans << endl;



	}
	return 0;
}
