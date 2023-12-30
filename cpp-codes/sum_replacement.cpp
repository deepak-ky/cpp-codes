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

node* build_tree()
{
	int d;
	cin >> d;

	if (d == -1)
	{
		return NULL;
	}
	else
	{
		node * temp_head = new node(d);
		temp_head->left = build_tree();
		temp_head->right = build_tree();
		return temp_head;
	}

}

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

bool is_leaf_node(node * head)
{
	if (head->left == NULL && head->right == NULL)
	{
		return true;
	}
	else return false;
}

int sum_replacement(node*&head)
{

	int original_data = head->data;
	int to_replace = 0;


	if (head->left)
	{

		if (is_leaf_node(head->left))
		{
			to_replace += head->left->data;
		}
		else
		{
			int left_return = sum_replacement(head->left);
			to_replace += left_return + head->left->data;
		}
	}

	if (head->right)
	{

		if (is_leaf_node(head->right))
		{
			to_replace += head->right->data;
		}
		else
		{
			int right_return = sum_replacement(head->right);
			to_replace += right_return + head->right->data;
		}
	}




	head->data = to_replace;
	return original_data;
}


int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		node * head = build_tree();
		print_level_by_level(head);

		cout << endl;


		int w = sum_replacement(head);

		cout << endl;

		print_level_by_level(head);


	}
	return 0;
}