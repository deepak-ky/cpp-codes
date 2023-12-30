#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<varname(x)<<" here : "<<x<<"\n"
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

void display_set(unordered_set<int> s )
{
	for (auto x : s)
	{
		cout << x << " ";
	}
	cout << endl;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int n = 20;
		int cap = 4;

		int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};


		unordered_set<int> s;

		unordered_map<int, int> last_index;

		int page_faults = 0;

		for (int i = 0; i < n; i++)
		{
			int a = pages[i];
			cout << "Ele here : " << a << endl;
			if (s.find(a) == s.end())
			{
				//The current element is not present in the set
				if (s.size() < cap)
				{
					s.insert(a);
					last_index[a] = i;
				}
				else
				{
					//we need to remove an element from the set , which has the lowest index
					int lru_ele;
					int lru_index = INT_MAX;
					for (auto ele : s)
					{
						if (last_index[ele] < lru_index)
						{
							lru_ele = ele;
							lru_index  = last_index[ele];
						}
					}

					s.erase(lru_ele);
					s.insert(a);

					last_index[a] = i;

				}


				page_faults++;

			}
			else
			{
				last_index[a] = i;
			}


			display_set(s);
			wer(page_faults);
			cout << endl;
		}


		cout << page_faults << endl;

	}
	return 0;
}
