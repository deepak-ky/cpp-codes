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
class Deque
{
	int size;
	int *a;
	int front;
	int rear;
public:
	Deque(int size)
	{
		this->size = size;
		a = new int[size];
		front = -1;
		rear = 0;
	}
	bool isEmpty()
	{
		return (front == -1);
	}
	bool isFull()
	{
		return ((front == 0 && rear == (size - 1)) || (front == rear + 1));
	}
	void insertFront(int data)
	{
		if (isFull())
		{
			cout << endl << "Deque is Full";
			return;
		}
		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else if (front == 0)
		{
			front = size - 1;
		}
		else
			front = front - 1;

		a[front] = data;
	}
	void insertLast(int data)
	{
		if (isFull())
		{
			cout << endl << "Deque is Full";
			return;
		}
		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else if (rear == (size - 1))
		{
			rear = 0;
		}
		else
			rear =  rear + 1;

		a[rear] = data;
	}
	void deleteFront()
	{
		if (isEmpty())
		{
			cout << "deque is empty";
		}
		if ( front == rear )
		{
			front = -1;
			rear = -1;
		}
		else
		{
			if (front == (size - 1))
			{
				front = 0;
			}
			else
				front = front + 1;
		}
	}
	void deleteLast()
	{
		if (isEmpty())
		{
			cout << "deque is empty";
		}
		if ( front == rear )
		{
			front = -1;
			rear = -1;
		}
		else
		{
			if (rear == (0))
			{
				rear = size - 1;
			}
			else
				rear = rear - 1 ;
		}
	}
	int getFront()
	{
		if (isEmpty())
		{
			cout << "Front does not exist";
			return -1;
		}
		return a[front];
	}
	int getRear()
	{
		if (isEmpty() || rear < 0)
		{
			cout << "Rear does not exist";
			return -1;
		}
		return a[rear];

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
	Deque de(5);
	de.insertFront(1);
	de.insertFront(2);
	de.getFront();
	de.insertFront(3);
	de.insertFront(4);
	de.insertFront(5);
	return 0;
}
