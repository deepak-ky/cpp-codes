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
void prime_sieve(int p[])
{
	for (int i = 3; i <= 100000; i += 2)
	{
		p[i] = 1;
	}

	for (int i = 3; i < 100000; i += 2)
	{


		if (p[i] == 1)
		{

			for (int j = (i * i); j < 100000; j = j + i)
			{

				p[j] = 0;
			}

		}
	}

	p[2] = 1;

	p[1] = p[0] = 0;


}
void print_and_return(stack<int> s1, int prime_number)
{
	cout << "\nhere:";
	stack<int> s2;
	stack<int> s3;
	while (s1.empty() == false)
	{
		int w = s1.top();
		if ((w) % prime_number == 0)
		{
			s2.push(w);
			s1.pop();
		}

	}
	cout << "\nThe b stack is : ";
	while (s2.empty() == false)
	{
		cout << s2.top() << endl;
		s2.pop();
	}

}
void insert_at_bottom(stack<int> &s, int t)
{
	if (s.empty() == true)
	{
		s.push(t);
		return;
	}
	int y = s.top();
	s.pop();
	insert_at_bottom(s, t);
	s.push(y);
}
void reversestack_using_recursion(stack<int> &s)
{
	if (s.empty() == true)
	{
		return;
	}
	int t = s.top();
	s.pop();
	reversestack_using_recursion(s);
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
	int p[100005] = {0};
	prime_sieve(p);
	int n, t;
	cin >> n >> t;
	int a[n];
	stack<int> s1;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s1.push(a[i]);
	}
	int prime_number = 2;
	for (int i = 1; i <= t; i++)
	{

		stack<int> s2;
		stack<int> s3;
		while (s1.empty() == false)
		{
			int w = s1.top();

			if ((w) % prime_number == 0)
			{
				s2.push(w);

			}
			else
			{
				s3.push(w);
			}
			s1.pop();
		}

		while (s2.empty() == false)
		{
			cout << s2.top() << endl;
			s2.pop();
		}
		while (s3.empty() == false)
		{
			s1.push(s3.top());
			s3.pop();
		}
		reversestack_using_recursion(s1);
		for (int j = (prime_number + 1);; j++)
		{
			if (p[j] == 1)
			{
				prime_number = j;
				break;
			}
		}
	}

	while (s1.empty() == false)
	{
		cout << s1.top() << endl;
		s1.pop();
	}
	return 0;
}
