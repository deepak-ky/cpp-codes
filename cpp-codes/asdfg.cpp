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
	int *arr;
	int ms;
	int cs;
	int front;
	int rear;
public:
	Queue(int default_size = 7)
	{
		this->front = 0;
		this->rear = default_size - 1;
		this->ms =   default_size;
		this->cs = 0;
		this->arr = new int[this->ms]();
	}
	bool isfull()
	{
		return this->ms == this->cs;
	}
	bool isempty()
	{
		return this->cs == 0;
	}
	void enque(int data)
	{
		if (!isfull())
		{
			this->rear = (this->rear + 1) % (this->ms);
			this -> arr[this->rear] = data;
			this->cs += 1;
		}
	}
	void deque()
	{
		if (!isempty())
		{
			this->front = (this->front + 1) % (this->ms);
			this->cs -= 1;
		}
	}
	int getfront()
	{
		return this -> arr[this->front];
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
	Queue q(10);
	for (int i = 1; i <= 6; i++)
	{
		q.enque(i);
	}
	q.deque();
	q.enque(8);
	while (q.isempty() == false)
	{
		cout << q.getfront() << " ";
		q.deque();
	}
	return 0;
}

