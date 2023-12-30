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
	//cin>>t;
	while (t--)
	{
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int k;
		cin >> k;


		deque<int> q;
		int i = 0;
		for (i = 0; i < k; i++)
		{
			while (!q.empty() && a[q.back()] >= a[i])
			{
				q.pop_back();
			}
			q.push_back(i);
		}


		cout << a[q.front()] << " ";


		int j = 1;
		for (int i = k; i < n; i++)
		{
			//remove indexes that are out of bounds
			while (!q.empty() && q.front() < j)
			{
				q.pop_front();
			}

			while (!q.empty() && a[q.back()] >= a[i])
			{
				q.pop_back();
			}

			q.push_back(i);

			cout << a[q.front()] << " ";

			j++;
		}

	}

	return 0;
}
