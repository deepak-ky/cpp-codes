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

class custom_compare
{

public:
	bool operator()(pair<string, int> p1, pair<string, int> p2)
	{
		if (p1.second <= p2.second)
		{
			return true;
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
		//The main logic of the program is :
		//Maximum debit will fulfill maximum credit
		//this is fine
		int n;
		cin >> n;
		int no_of_transactions;
		cin >> no_of_transactions;


		unordered_map<string , int>  mp;

		//a b ko kitne paise dene hain
		// will get two strings and a int
		while (no_of_transactions--)
		{
			string giver;
			string reciver;
			int money;
			cin >> giver >> reciver >> money;
			// if (mp.find(giver) == mp.end())
			// {
			// 	mp[giver] = 0;
			// }
			// if (mp.find(reciver) == mp.end())
			// {
			// 	mp[reciver] = 0;
			// }
			mp[giver] -= money;
			mp[reciver] += money;
		}


		//Now we have to create a multiset of all the values
		multiset<pair<string, int> , custom_compare > ms;
		for (auto x : mp)
		{
			ms.insert(x);
		}


		int cnt_of_transaction = 0;

		//amount settlements
		while (!ms.empty())
		{
			auto it = ms.begin();
			auto it1 = ms.end();
			it1--;
			int curr_debit = (*it).se;
			int credit_curr = (*it1).se;

			ms.erase(it);
			ms.erase(it1);

			int max_abs = min(-curr_debit, credit_curr);
			cnt_of_transaction++;
			curr_debit += max_abs;
			credit_curr -= max_abs;

			cout << (*it).f << " will give " << max_abs << " to " << (*it1).f << endl;

			//when both are zero the while loop will break
			if (curr_debit != 0)
			{
				ms.insert({(*it).f, curr_debit});
			}
			if (credit_curr != 0)
			{
				ms.insert({(*it1).f, credit_curr});
			}

		}

		cout << "The total number of cnt_of_transaction is : " << cnt_of_transaction;
	}
	return 0;
}
