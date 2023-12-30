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

class solve
{

	queue<int> q;
	int prod;
	int size;
	int number_of_zeroes_in_queue;
public:
	solve(int k)
	{
		prod = 1;
		number_of_zeroes_in_queue = 0;
		size = k;
	}
	void push(int x)
	{
		if (x)
		{
			q.push(x);
			prod *= x;

		}
		else
		{
			q.push(x);
			number_of_zeroes_in_queue++;
		}
	}
	int poll()
	{
		int w = q.front();
		if (w == 0)
		{
			number_of_zeroes_in_queue--;
		}
		else if (w != 0)
		{
			q.pop();
			prod = prod / w;
		}

		return w;
	}
	int get()
	{

		if (number_of_zeroes_in_queue > 0)
		{
			return 0;
		}
		else return prod;
	}

};

int32_t main()
{
//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	solve s(5);
	s.push(2);

	s.push(3);
	int w = s.poll();


	cout << s.get();

	return 0;
}
