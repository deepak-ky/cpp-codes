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

bool is_stack_permutation(int *pushed, int *popped, int n)
{
	int i = 0;
	int j = 0;
	stack<int> s;

	while ( j < n )
	{
		if (s.empty())
		{
			s.push(pushed[i]);
			i++;
		}
		else
		{
			if (popped[j] == s.top())
			{
				s.pop();
				j++;
			}
			else
			{
				if (i == n)
				{
					return false;
				}

				s.push(pushed[i]);
				i++;
			}
		}


	}

	return true;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		int pushed[] = {1, 2, 3, 4, 5};
		int popped[] = {4 , 5 , 3 , 2 , 1 };
		int n = sizeof(pushed) / sizeof(int);

		if (is_stack_permutation(pushed, popped, n))
		{
			yes;
		}
		else no;
	}
	return 0;
}
