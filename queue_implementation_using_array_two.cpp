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

class Queue
{
	int front;
	int rear;
	int *a;
	int max_size;
public:
	Queue(int size)
	{
		a = new int[size];
		max_size = size;
		front = -1;
		rear = -1;
	}

	void display_queue()
	{
		wer(front);
		wer(rear);
		out(a, max_size);
	}

	bool is_empty()
	{
		if (front == -1 && rear == -1)
		{
			//cout << "Queue is empty";
			return true;
		}
		else return false;
	}

	bool is_full()
	{
		//check here
		if ((rear + 1) % max_size == front)
		{
			//cout << "Queue is full";
			return true;
		}
		else return false;
	}

	void push(int x)
	{

		if (is_full())
		{
			cout << "Queue is full cannot push more elements \n";
			return;
		}
		else if (is_empty())
		{
			front = 0;
			rear = 0;
		}
		else
		{
			rear = (rear + 1) % max_size;
		}

		a[rear] = x;

		display_queue();

	}

	void pop()
	{
		if (is_empty())
		{
			cout << "Queue is empty cannot pop elements \n";
			return;
		}
		else if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = (front + 1) % max_size;
		}

		display_queue();
	}

	int front_element()
	{
		if (is_empty())
		{
			cout << "Queue is empty !!";
			return -1;
		}

		else return a[front];
	}
};


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		Queue q(5);
		q.push(1);
		q.push(4);
		q.push(5);
		q.push(6);
		q.pop();
		q.push(7);
		q.push(8);
		q.push(9);
		q.pop();

		cout << q.front_element();
	}
	return 0;
}
