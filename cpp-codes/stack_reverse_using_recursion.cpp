#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
void insert_at_bottom(stack<int> &s, int t)
{
	if (s.empty() )
	{
		s.push(t);
		return;
	}
	int y = s.top();
	s.pop();
	insert_at_bottom(s, t);
	s.push(y);
}
void reversestack_using_rec(stack<int>& s)
{
	if (s.empty())
	{
		return;
	}
	int t = s.top();
	s.pop();
	reversestack_using_rec(s);
	insert_at_bottom(s, t);
}
int32_t main()
{

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << "\nStack now : ";
	while (s.empty() == false)
	{
		cout << s.top() << " ";
		s.pop();
	}
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << "\nStack size is : " << s.size();
	reversestack_using_rec(s);
	cout << "\nThe reversed stack is : ";
	while (s.empty() == false)
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
