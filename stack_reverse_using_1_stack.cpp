#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int                          long long
#define watch(var,x)                 cout <<"\nValue of x here is : "<<(x) << endl
#define mod                          1000000007
void transfer(stack<int> &s, stack<int> &s1, int value)
{
	for (int i = 1; i <= value; i++)
	{
		int w = s.top();
		s1.push(w);
		s.pop();
	}
}
void reversestack(stack<int>& s)
{
	stack<int> s1;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{
		int value = n - i - 1;
		int t = s.top();
		s.pop();
		transfer(s, s1, value);
		s.push(t);
		transfer(s1, s, value);
	}
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
	reversestack(s);
	cout << "\nThe reversed stack is : ";
	while (s.empty() == false)
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
