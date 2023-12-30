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

class process
{
public:
	string id;
	int arrival;
	int burst;
};


bool compare(process p1 , process p2)
{
	if (p1.arrival <= p2.arrival)
	{
		return true;
	}
	else return false;
}


class custom_compare
{
public:
	bool operator()(process const& p1, process const& p2)
	{
		if (p1.burst > p2.burst)
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
		int n;
		n = 5;
		//n = 4;
		//n = 2;
		string process_id[n] = {"P1", "P2", "P3", "P4", "P5"};
		//string process_id[n] = {"P1", "P2", "P3", "P4"/*, "P5"*/};
		//string process_id[n] = { "P1" , "P2"};
		int arr[n] = {3, 1, 4, 0, 2};
		//int arr[n] = {2, 0, 4, 5};
		//int arr[n] = {0, 6};
		int bur[n] = {1, 4, 2, 6, 3};
		//int bur[n] = {3, 4, 2, 4};
		//int bur[n] = {3, 9};

		process p[n];

		for (int i = 0; i < n; i++)
		{
			p[i].id = process_id[i];
			p[i].arrival = arr[i];
			p[i].burst = bur[i];
		}

		sort(p, p + n, compare);


		for (int i = 0; i < n; i++)
		{
			cout << p[i].id << " " << p[i].arrival << " " << p[i].burst << endl;
		}

		int current_time = 0;

		priority_queue<process, vector<process>, custom_compare> pq;

		pq.push(p[0]);

		int i = 1;

		map<string, vector<int>> mp;

		cout << endl << endl;

		cout << "Id " << "\t" << "AT" << "\t" << "BT" << "\t" << "ET" << "\t" << "TAT" << "\t" << "WT" << endl;

		while (1)
		{
			process c = pq.top();
			pq.pop();


			int exit_time = current_time + c.burst;
			current_time = exit_time;



			mp[c.id].pb(c.arrival);
			mp[c.id].pb(c.burst);
			mp[c.id].pb(exit_time);
			mp[c.id].pb(exit_time - c.arrival);
			mp[c.id].pb(exit_time - c.arrival - c.burst);


			if (i < n)
			{
				current_time = max(current_time, p[i].arrival);
			}
			while (p[i].arrival <= current_time && i < n)
			{
				pq.push(p[i]);
				i++;
			}

			if (pq.empty() && i == n)
			{
				break;
			}
		}


		for (auto x : mp)
		{
			cout << x.first << "\t";
			for (auto y : x.second)
			{
				cout << y << "\t";
			}
			cout << endl;
		}

		//what should be my algo

		//sort them on the basis of the arrival time
		//maintain a priority queue
		//insert the first job with minimum arrival time inside the queue

		//jobs inside would be sorted on the basis of minimum burst time

		//then do a while loop , store a count of the current time , pop the top element from the list
		//insert all the jobs in the pq on the basis of whose arrival time is less than current time
	}
	return 0;
}
