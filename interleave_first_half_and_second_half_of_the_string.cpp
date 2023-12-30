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

void interleave(queue<int> &q)
{
	queue<int> q1;
	queue<int> q2;

	int w = q.size();
	int i = 0;
	while (i < w / 2)
	{
		int w = q.front();
		q1.push(w);
		q.pop();
		i++;
	}

	i = 0;
	while (i < w / 2)
	{
		int w = q.front();
		q2.push(w);
		q.pop();
		i++;
	}


	i = 0;
	while (i < w)
	{
		if (i & 1)
		{
			int w = q2.front();
			q.push(w);
			q2.pop();
		}
		else
		{
			int w = q1.front();
			q.push(w);
			q1.pop();
		}

		i++;
	}
}
void print_queue(queue<int> q)
{
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
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
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		print_queue(q);

		interleave(q);

		print_queue(q);
	}
	return 0;
}
