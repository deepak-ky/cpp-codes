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
bool checkif(int arrival[], int duration[], int mid, int n)
{
	int roomno[100005] = {0};

	int visited[100005] = {0};
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{

		if (i == 0)
		{
			roomno[0] = duration[0];

			visited[0] = 1;
			cnt++;
		}
		else
		{
			int gap = arrival[i] - arrival[i - 1];

			for (int j = 0; j < n; j++)
			{
				int we = roomno[j] - gap;
				if (we <= 0)
				{
					roomno[j] = 0;
				}
				else
				{
					roomno[j] = we;
				}
			}

			//find out the first room no which is 0
			int getroom;
			for (int j = 0; j < n; j++)
			{
				if (roomno[j] == 0)
				{
					getroom = j;
					break;
				}
			}


			if (visited[getroom] == 0)
			{
				cnt++;
				visited[getroom] = 1;
				roomno[getroom] = duration[i];
			}
			else if (visited[getroom] == 1)
			{
				roomno[getroom] = duration[i];
			}

		}
		if (cnt > mid)
		{

			return false;
		}

	}
	return true;
}


class g
{
public:
	int arrival;
	int duration;
};
bool compare(g a, g b)
{
	return a.arrival < b.arrival;
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	g guest[n];
	for (int i = 0; i < n; i++)
	{
		cin >> guest[i].arrival;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> guest[i].duration;
	}
	sort(guest, guest + n, compare);
	int arrival[n], duration[n];
	for (int i = 0; i < n; i++)
	{
		arrival[i] = guest[i].arrival;
		duration[i] = guest[i].duration;
	}

	int s = 1;
	int e = n;
	int ans = INT_MAX;
	while (s <= e)
	{
		int mid = (s + e) / 2;
		wer(mid);
		if (mid == 9)
		{
			cout << endl << "s is : " << s;
			cout << endl << "e is : " << e;
		}
		if (checkif(arrival, duration, mid, n))
		{
			cout << "\ngetting executed : ";

			ans = mid;
			e = mid - 1;
		}
		else
		{

			s = mid + 1;
		}

	}
	cout  << endl << ans;
	return 0;
}
