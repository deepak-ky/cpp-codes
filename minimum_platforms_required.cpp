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

class compare
{
public:

	bool operator()(pair<int, int> const& p1 , pair<int, int> const& p2)
	{
		//return true then p2 will get popped first
		if (p1.second > p2.second)
		{
			return true;
		}
		else return false;
	}
};

bool compare_vector(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first <= p2.first)
	{
		return true;
	}
	else return false;
}


void display_pq(  priority_queue< pair<int, int> , vector<pair<int, int>> , compare > pq )
{
	cout << "Pq here : ";
	while (!pq.empty())
	{
		cout << " { " << pq.top().first << " , " << pq.top().second << " } ,";
		pq.pop();
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
		int n;
		n = 6;
		int arr[] =  {900, 940, 950, 1100, 1500, 1800};
		int dep[] =  {910, 1200, 1120, 1130, 1900, 2000};

		vector<pair<int, int>> v;

		for (int i = 0; i < n; i++)
		{
			v.push_back({arr[i], dep[i]});
		}

		sort(v.begin(), v.end(), compare_vector);

		priority_queue< pair<int, int> , vector<pair<int, int>> , compare > pq;

		pq.push(v[0]);

		int ans = 1;

		int i = 1;

		while (i < n)
		{
			wer(i);
			while (!pq.empty() && pq.top().second < v[i].first)
			{

				pq.pop();
			}

			pq.push(v[i]);


			display_pq(pq);

			int w = pq.size();

			ans = max(ans, w);

			i++;


		}


		cout << ans << endl;
	}
	return 0;
}
