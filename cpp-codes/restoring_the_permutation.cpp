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



int32_t main()
{
	init();
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int *a = new int[n];
		unordered_map<int, int> freq;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			freq[a[i]]++;
		}

		set<int> less_set;
		for (int i = 1; i <= n; i++)
		{
			less_set.insert(i);
		}
		set<int> more_set;
		for (int i = 1; i <= n; i++)
		{
			more_set.insert(i);
		}





		int small[n];
		int large[n];

		//If the frequency of a number is 1 , then it is , its first and last occ


		int i = 0;
		while (i < n)
		{
			int c = a[i];
			if (freq[c] == 1)
			{
				//first occurence of the number
				small[i] = large[i] = c;
				auto it = less_set.find(c);
				auto it1 = more_set.find(c);
				less_set.erase(it);
				more_set.erase(it1);
			}
			else
			{

				small[i] = large[i] = c;
				auto it = less_set.begin();
				auto it1 = more_set.find(c);
				it1--;
				bool check = false;
				for (int j = i + 1; j < freq[c] + i; j++)
				{
					small[j] = *it;
					large[j] = *it1;
					it++;
					if (it1 != more_set.begin())
					{
						it1--;
					}
					else check = true;


				}
				if (check == false)
					it1++;
				//wer(*it1);
				auto it2 = more_set.find(c);
				it2++;

				less_set.erase(less_set.begin(), it);
				more_set.erase(it1, it2);

				auto final_it = less_set.find(c);
				less_set.erase(final_it);

				//at the end I also have to remove the current character from both the set

			}
			i += freq[c];

		}

		for (auto x : small) cout << x << " ";
		cout << endl;
		for (auto y : large) cout << y << " ";
		cout << endl;


	}
	return 0;
}

