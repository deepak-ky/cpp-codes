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

class Stack
{
	int top;
	int max_size;
	int *a;
public:
	Stack(int s)
	{
		top = -1;
		max_size = s;
		a = new int[max_size];
	}

	void push(int x)
	{
		if (top == max_size - 1)
		{
			cout << "Stack is Full ! ";
		}
		else
		{
			top++;
			a[top] = x;
		}
	}

	void pop()
	{
		if (top == -1)
		{
			cout << "Stack is Empty ! ";
		}
		else
		{
			top--;
		}
	}

	int top_element()
	{
		if (top == -1)
		{
			cout << "Stack is Empty!";

			//return -1;

		}
		else
		{
			return a[top];
		}
	}

	bool is_empty()
	{
		if (top == -1)
		{
			return true;
		}
		else return false;
	}

	bool is_full()
	{
		if (top == max_size - 1)
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
		Stack s(5);
		s.push(1);
		s.push(3);
		s.push(9);
		s.push(2);
		s.push(7);

		while (!s.is_empty())
		{
			cout << s.top_element() << " ";
			s.pop();
		}

		s.pop();
	}
	return 0;
}
