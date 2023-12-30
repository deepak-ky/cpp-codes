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

void insert_at_bottom(stack<int> &s , int w)
{
	if (s.empty())
	{
		s.push(w);
		return;
	}
	else
	{
		int g = s.top();
		s.pop();
		insert_at_bottom(s, w);
		s.push(g);
		return;
	}
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);
		//s.push(1);

		insert_at_bottom(s, 4);

		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}

	}
	return 0;
}
