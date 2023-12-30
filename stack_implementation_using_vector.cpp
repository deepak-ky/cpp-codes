#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
class Stack
{
	vector<int> v;
public:
	void push(int d)
	{
		v.push_back(d);
	}
	bool empty()
	{
		return v.size() == 0;
	}
	void pop()
	{
		if (!empty())
		{
			v.pop_back();
		}
	}
	int top()
	{
		return v[v.size() - 1];
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
	Stack s;
	for (int i = 1; i <= 5; i++)
	{
		s.push(i * i);
	}
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
