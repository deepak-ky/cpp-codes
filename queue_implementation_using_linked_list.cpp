#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define varname(name)                #name
#define mod                          1000000007
#define wer(x)                       cout<<"\n"<<varname(x)<<" here : "<<x.
#define out(a,n)                     cout<<"\n"<<varname(a)<<" here is : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl
#define test                         int t; cin>>t; while(t--)
#define asdf(a,n)                    for(int i=0;i<n;i++)  cin>>a[i]
class Queue
{
	int cs;
	list<int> q;
public:
	Queue()
	{
		this->cs = 0;
	}
	bool isempty()
	{
		return this->cs == 0;
	}
	void enque(int data)
	{
		this->q.push_back(data);
		this->cs += 1;

	}
	void deque()
	{
		if (!isempty())
		{
			this->q.pop_front();
			this->cs -= 1;
		}
	}
	int getfront()
	{
		return this->q.front();
	}
	int getback()
	{
		return this->q.back();
	}
};
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	Queue q;
	for (int i = 5; i <= 10 ; i++)
	{
		q.enque(i);
	}
	q.deque();
	q.enque(8);
	while (q.isempty() == false)
	{
		cout << q.getback() << " ";
		q.deque();
	}
	return 0;
}

