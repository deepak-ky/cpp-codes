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

class two_stacks
{
	int *a;
	int max_size;
	int top1, top2;
public:
	two_stacks(int n)
	{
		a = new int[n];
		max_size = n;
		top1 = -1;
		top2 = max_size;

	}
	void push1(int x)
	{
		if (top1 == top2 - 1)
		{
			cout << "Stack 1 full \n";
			return;
		}
		else
		{

			top1++;
			a[top1] = x;
		}
	}
	void push2(int x)
	{
		if (top2 == top1 + 1)
		{
			cout << "Stack 2 full \n";
			return;
		}
		else
		{
			top2--;
			a[top2] = x;
		}
	}
	//return the elements also in pops
	int pop1()
	{
		if (top1 == -1)
		{
			return -1;
		}
		else
		{
			int w = a[top1];
			top1--;
			return w;
		}
	}

	int pop2()
	{
		if (top2 == max_size)
		{
			return -1;
		}
		else
		{
			int w = a[top2];
			top2++;
			return w;
		}
	}
};


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		two_stacks s(7);
		s.push1(1);
		s.push1(2);
		s.push1(3);
		s.push1(4);
		s.push2(59);
		s.push2(58);
		s.push2(57);
		cout << s.pop2();
		s.push1(56);
		s.push1(54);
		cout << endl;
		cout << s.pop1();
	}
	return 0;
}
