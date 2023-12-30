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

class fuel_points
{
public:
	int dist;
	int fuel;
};

bool compare(fuel_points f1 , fuel_points f2)
{
	if (f1.dist <= f2.dist)
	{
		return true;
	}
	else return false;
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
		fuel_points f[n];
		for (int i = 0; i < n; i++)
		{
			cin >> f[i].dist >> f[i].fuel;
		}
		int total_dist;
		int curr_fuel;
		cin >> total_dist >> curr_fuel;
		for (int i = 0; i < n; i++)
		{
			f[i].dist = total_dist - f[i].dist;
		}
		sort(f, f + n, compare);
		int at_position = 0;
		int cnt = 0;

		bool flag = false;
		priority_queue<int> pq;

		//Have to move from a fueling station to a fueling station

		int pos = 0;
		while (pos < n)
		{
			//If I have enough fuel in the tank to move to the next fueling station
			//from the current fuelling station without getting fuelled
			if (curr_fuel >= f[pos].dist - at_position)
			{
				curr_fuel -= (f[pos].dist - at_position);
				//If I can reach a fuelling station, I will insert in the priority queue
				//For later use
				pq.push(f[pos].fuel);
				at_position = f[pos].dist;
			}

			//If I do not have enough fuel to reach the next station
			else
			{
				if (pq.empty()) // I have no fuel stations to use
				{
					flag = true;
					break;
				}
				//If I have some fuel stations to use , I will use the one with the most capacity
				cnt++;
				curr_fuel += pq.top();
				pq.pop();
				//This continue will take the control flow to the the starting if statement
				//AND NOT THE NEXT ITERATION
				continue;
			}
			pos++;


		}

		if (flag)
		{
			cout << -1 << endl;
		}
		else
		{
			//The amount of dist. that I need to cover is
			int w = total_dist - f[n - 1].dist;
			if (curr_fuel >= w)
			{
				cout << cnt << endl;
			}
			else
			{
				//If I cannot reach the town , I will see whether I have some fuel
				//stations left to be used in the priority queue
				while (curr_fuel < w)
				{
					if (pq.empty())
					{
						flag = true;
						break;
					}
					cnt++;
					curr_fuel += pq.top();
					pq.pop();
				}
				if (flag)
				{
					cout << -1 << endl;
				}
				else cout << cnt << endl;

			}
		}


	}
	return 0;
}
