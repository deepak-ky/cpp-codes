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


//Method 1 : O[1] and O[N]  space
class my_stack
{
	stack<int> s;
	stack<int> curr_max;
public:
	void push(int x)
	{
		if (s.empty())
		{
			s.push(x);
			curr_max.push(x);
		}
		else
		{
			if (x > curr_max.top())
			{
				s.push(x);
				curr_max.push(x);
			}
			else
			{
				s.push(x);
			}
		}

	}
	void pop()
	{

		if (s.empty())
		{
			return;
		}
		else
		{
			int w = s.top();
			s.pop();
			if (s.empty())
			{
				curr_max.empty();
				return;
			}
			else
			{
				if (w == curr_max.top())
				{
					curr_max.pop();
				}
			}
		}
	}
	void get_max()
	{
		if (s.empty())
		{
			cout << "The stack is empty!!";
		}
		else cout << "Ther current maximum element is  : " << curr_max.top() << endl;
	}
	void peek()
	{
		if (!s.empty())
		{
			cout << "The top most element  is : " << s.top();
			cout << endl;
		}
	}

};

class  my_stack_2
{
	stack<pair<int, int>> s;
	int curr_max;
public:
	my_stack_2()
	{
		curr_max = INT_MIN;
	}
	void push(int x)
	{
		if (s.empty())
		{
			curr_max = x;
			s.push({x, INT_MIN});
		}
		else
		{
			if (x > curr_max)
			{
				s.push({x, curr_max});
				curr_max = x;
			}
			else
			{
				s.push({x, INT_MIN});
			}
		}
	}
	void pop()
	{
		if (s.empty())
		{
			return;
		}
		else
		{
			pair<int, int>  w = s.top();
			s.pop();
			if (s.empty())
			{
				curr_max = INT_MIN;
				return;
			}
			else
			{
				if (w.f == curr_max)
				{
					curr_max = w.se;
				}
			}

		}
	}
	void get_max()
	{
		cout << "The maximum element is : " << curr_max;
		cout << endl;
	}


};


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		my_stack_2 s;
		s.push(3);
		s.push(5);
		s.get_max();
		s.push(7);
		s.push(19);
		s.get_max();
		s.pop();
		s.get_max();
		s.pop();
		s.get_max();
		s.pop();
		s.get_max();
		s.pop();
		s.get_max();


	}
	return 0;
}
