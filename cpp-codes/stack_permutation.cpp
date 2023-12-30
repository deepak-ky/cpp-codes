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

bool is_stack_permutation(int *a, int n)
{
	int max_till_now = *min_element(a, a + n) - 1;
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < max_till_now)
		{
			if (s.empty())
			{
				return false;
			}
			else if (s.top() == a[i])
			{
				s.pop();
			}
			else
			{
				return false;
			}
		}
		else if (a[i] > max_till_now)
		{
			for (int j = max_till_now + 1; j < a[i]; j++)
			{
				s.push(j);
			}
			max_till_now = a[i];
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

		//Question is can 1 , 2 , 3 ,4 ... n form the given below array

		// Refer to valid_stack_sequences.cpp


		int a[] = {4 , 5 , 3 , 2 , 1 };
		int n = sizeof(a) / sizeof(int);

		if (is_stack_permutation(a, n))
		{
			yes;
		}
		else no;


	}
	return 0;
}
