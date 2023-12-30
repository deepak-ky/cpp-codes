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

int number_of_nodes(node * head)
{
	if (head == NULL)
	{
		return 0;
	}

	int l = number_of_nodes(head->left);
	int h = number_of_nodes(head->right);

	return l + h + 1;
}

int sum_of_nodes(node * head)
{
	if (head == NULL)
	{
		return 0;
	}

	int l = sum_of_nodes(head->left);
	int r = sum_of_nodes(head->right);

	return head->data + l + r;
}

int32_t main()
{
	init();
	int t = 1;
	//cin>>t;
	while (t--)
	{
		node * head = build_tree();
		cout << number_of_nodes(head);
		cout << endl;
		cout << sum_of_nodes(head);
	}
	return 0;
}
