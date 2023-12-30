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


		//THE RULE IS : IF THIS FUNCTION RETURNS TRUE ,
		//                                               THEN I2 WILL GET POPPED FIRST

		//  I2 WILL BE AT THE TOP , AND I1 WILL BE BELOW IT.


		//              ELSE IF THIS FUNCTION RETURS FALSE,
		//                                                   THEN I1 WILL GET POPPED FIRST




		double d1 = double(i1.value / i1.weight);
		double d2 = double(i2.value / i2.weight);

		if (d1 < d2)
		{
			return true;
		}
		else if (d1 == d2)
		{
			return false;
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




		priority_queue<Item, vector<Item>, compare> pq;

		Item i1;
		i1.value = 100;
		i1.weight = 50;


		Item i2;

		i2.value = 40;
		i2.weight = 20;

		// Item i3;
		// i3.value = 10;
		// i3.weight = 1;


		pq.push(i1);
		pq.push(i2);
		//pq.push(i3);


		Item it = pq.top();

		cout << it.weight;

	}
	return 0;
}
