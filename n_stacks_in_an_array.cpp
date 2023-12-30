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

class k_stacks
{
	int n;
	int k;
	int *stack_data;
	int *next_index;
	int *top_of_stack;
	int next_available;
public:

	k_stacks(int size, int k1)
	{
		n = size;
		k = k1;
		stack_data = new int[n];
		next_index = new int[n];
		for (int i = 0; i < n; i++)
		{
			next_index[i] = i + 1;
		}
		top_of_stack = new int[k];
		for (int i = 0; i < k; i++)
		{
			top_of_stack[i] = -1;
		}
		next_available = 0;
	}

	void display()
	{
		out(top_of_stack, k);
		out(stack_data, n);
		out(next_index, n);
		wer(next_available);
	}

	void push(int stack_number , int x)
	{
		if (next_available == n)
		{
			cout << "Stack is full";
			return;
		}

		int w = top_of_stack[stack_number];
		int init_available_index = next_available;

		stack_data[next_available] = x;
		next_available = next_index[next_available];

		top_of_stack[stack_number] = init_available_index;
		next_index[init_available_index] = w;

		display();
	}

	int pop(int stack_number)
	{

		if (top_of_stack[stack_number] == -1)
		{

			return -1;
		}

		int current_top = top_of_stack[stack_number];
		int new_top = next_index[current_top];
		top_of_stack[stack_number] = new_top;

		next_index[current_top] = next_available;
		next_available = current_top;

		display();

		return stack_data[current_top];


	}

};

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		k_stacks ks(6, 3);
		//  k_stacks ks(10, 3);   --> for gfg part


		ks.push(0, 5);
		ks.push(0, 6);
		ks.push(1, 7);
		cout << ks.pop(0) << endl;
		cout << ks.pop(0) << endl;
		cout << ks.pop(0) << endl;

		ks.push(1, 7);
		ks.push(2, 9);
		ks.push(0, 44);
		//s.pop(1);
		ks.push(2, 45);
		ks.push(0, 12);
		ks.push(1, 13);

		/*// Let us put some items in stack number 2
		ks.push(2, 15);
		ks.push(2, 45);

		// Let us put some items in stack number 1
		ks.push(1, 17);
		ks.push(1, 49);
		ks.push(1, 39);

		// Let us put some items in stack number 0
		ks.push(0, 11);
		ks.push(0, 9);
		ks.push(0, 7);

		cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
		cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
		cout << "Popped element from stack 0 is " << ks.pop(0) << endl;*/
	}
	return 0;
}
