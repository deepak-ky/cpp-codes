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

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

void print_level_by_level(node * head)
{
	queue<node*> q;
	q.push(head);
	q.push(NULL);

	while (1)
	{
		node*f = q.front();
		q.pop();

		if (f)
		{
			cout << f->data << " ";
			if (f->left) q.push(f->left);
			if (f->right) q.push(f->right);
		}
		else
		{
			if (q.empty())
			{
				break;
			}
			else
			{
				cout << "\n";
				q.push(NULL);

			}
		}
	}
	return;
}

int idx;

node * build_tree(int pre_order_array[], int in_order_array[], int s, int e)
{
	if (s > e)
	{
		return NULL;
	}

	int to_find = pre_order_array[idx];
	idx++;
	int i = 0;
	for (i = s; i <= e; i++)
	{
		if (in_order_array[i] == to_find)
		{
			break;
		}
	}

	node * head = new node(in_order_array[i]);
	head->left = build_tree(pre_order_array, in_order_array, s, i - 1);
	head->right = build_tree(pre_order_array, in_order_array, i + 1, e);
	return head;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{

		int pre_order_array[] = {1, 2, 3, 4, 8, 5, 6, 7};
		int in_order_array[] = {3, 2, 8, 4, 1, 6, 7, 5};

		//pre => root,left,right
		//in  => left,root,right

		int n = sizeof(in_order_array) / sizeof(int);

		idx = 0;


		node * head = build_tree(pre_order_array, in_order_array, 0, n - 1);

		print_level_by_level(head);



	}
	return 0;
}
