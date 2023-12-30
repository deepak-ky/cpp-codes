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

class activity_times
{
public:
	int start_time;
	int end_time;

};

bool compare(activity_times t1, activity_times t2)
{
	if (t1.end_time <= t2.end_time)
	{
		return true;
	}
	else return false;
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
		activity_times* timings = new activity_times[n];
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			timings[i].start_time = a;
			timings[i].end_time = b;
		}
		sort(timings, timings + n, compare);

		// for (int i = 0; i < n; i++)
		// {
		// 	cout << timings[i].start_time << " " << timings[i].end_time << endl;
		// }

		int i = 1;
		int current_end_time = timings[0].end_time;
		int cnt = 1;
		while (i < n)
		{
			if (timings[i].start_time >= current_end_time)
			{
				cnt++;
				current_end_time = timings[i].end_time;
				i++;
			}
			else
			{
				i++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
